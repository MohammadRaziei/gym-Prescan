# -*- coding: utf-8 -*-
"""
Created on Sat May 18 15:47:01 2019

@author: MohammadRaziei
"""

import gym
from gym import error, spaces, utils
from gym.utils import seeding

from gym_prescan.envs.PrescanEnviroment2 import *

import numpy as np
from pandas import Series



class PrescanEnv2(gym.Env):
    def make(self,experimant_name,host='localhost'):
        set_experimant(experimant_name)
        self.enviroment = Enviroment(outport=8031,inport=8070,host=host)
        self.enviroment.create_model('Toyota_Yaris_Hatchback_1','StraightRoad_22')


    def __init__(self, 
                    experimant_name='PreScan_Vissim_Python_0',
                    host = 'localhost',
                    close_window=False,
                    delay=0.0,
                    nget=1,
                    verbose=False):
        # super(StockTradingEnv, self).__init__()
        self.make(experimant_name,host=host)
        super().__init__() 

        self.action_space = spaces.Discrete(6)
        self.observation_space = spaces.Box(low=0, high=255, shape= (1, 38), dtype=np.float16)
       
        self.__close__window__ = close_window
        self.delay = delay #s
        self.nget = nget
        self.verbose = verbose
        
        self.__action__ = [0, 0]
        self.__rewards__ = []
        self.__reset__ = 0
        self.__step__ = 0
        self.__sep__ = 25
        print('Enviroment is created')




    def create(self, car_name=None, road_name=None):
        self.enviroment.create_model(car_name, road_name)

        ##self.Reward.build()

    def reset(self):
        """Resets the state of the environment and returns an initial observation.
        Returns:
            observation (object): the initial observation.
        """
        self.__rewards__ = []
        self.__reset__ += 1
        self.__step__ = 0
        if self.verbose:
            print("[{}]>> env.reset()".format(self.__reset__))
            print('='*self.__sep__)
        self.__action__ = [0, 0]
        self.enviroment.reset()
        start_state = self._next_observation()
        return start_state

    def step(self, action):
        self.__step__ += 1
        # if self.verbose:
            # print("[{}]>>[{}]: env.step({})".format(self.__reset__,self.__step__,action))
        self.send(action)
        if self.delay > 0 :
            sleep(self.delay)
        for _ in range(self.nget):
            self.render_()
            if self.done:
                break

        observation = self._next_observation()
        reward = self.calc_reward()
        done = self.done
        info = {'Collision':self.collision ,'Position':self.agent['data']['Position']}

        self.__rewards__.append(reward)
        if self.verbose:
            print("[{}]>>[{}]: env.step({})".format(self.__reset__,self.__step__,action))
            print('action:{}'.format(self.__action__))
            print('reward:{1}\nobservation:\n{0}\ndone:{2}'.format(observation,reward,done))
            if done:
                print(self.collision)
                print(self.agent['data']['Position'])
                print('.'*self.__sep__)
                print('** Rewards description :')
                print(Series(self.__rewards__).describe())
                print('#'*self.__sep__)
            else:
                print('-'*self.__sep__)
        return observation, reward, done, info



    def render_(self):
        data = self.enviroment.get()
        self.agent = self.enviroment.agent
        self.collision = self.enviroment.collision
        self.Time = self.enviroment.data['Time']
        # self.done = bool(self.enviroment.data['done'])
        self.done = self.enviroment.done
        return data
    
    def render(self):
        if self.verbose:
            print("env.render()")
        self.render_()

    def calc_reward(self):
        lanewidth = self.enviroment.road.laneWidth
        vel_sim = self.agent['data']['Velocity']
        vel_cmd = self.__action__[1]
        Vel = 0.8 * vel_sim + 0.2 * vel_cmd

        Longitudinal_reward = reward_velocity(Vel,28) *1.5
        # Lateral_reward = -0.5  if self.__action__[0] != 0 else 0
        Collision_reward = -25 if self.collision['Occurred'] else 0
        Violation_reward = -0.75 * (np.abs(self.__action__[0] - self.__action_old__[0])/lanewidth)
        Nearby_reward = nearby_reward_linear(self.__obs__[13],-2.5,1.5) +\
                        nearby_reward_linear(self.__obs__[23],-2.5,1.5)
        reward_T = Longitudinal_reward + Collision_reward + Violation_reward + Nearby_reward
        return reward_T

    def seed(self):
        pass

    def send(self,action):
        self.__action__ = self.action_translate(action)
        self.enviroment.send(self.__action__)

    def _next_observation(self):
        self.render_()
        obs = np.zeros((1,36),dtype=np.float)
        car = self.agent
        theta = car['Sensors'][0]['data']['theta']
        Range = car['Sensors'][0]['data']['Range']

        for i in range(len(theta)):
            t = int((theta[i] + 180 )/10)
            r = Range[i]
            if obs[0,t] != 0:
                obs[0,t] > r
                continue
            obs[0,t] = r
        extra = [car['data']["Velocity"], car['data']["Position"]["y"]]
        self.__obs__ = np.append(obs, extra)
        return self.__obs__ 
        

    def action_translate(self,action):
        lanewidth = self.enviroment.road.laneWidth
        self.__action_old__ = self.__action__
        vel = self.agent['data']['Velocity']
        offset = self.__action__[0]


        if action == 0 :
            offset = -lanewidth
        if action == 1 :
            offset = 0 
        if action == 2 :
            offset = lanewidth
        if action == 3 :
            vel = action_velocity(vel,True)
        if action == 4 :
            vel = action_velocity(vel,False)

        self.__action__ = [offset,vel]

        return self.__action__

    def __del__(self):
        self.close()


    def close(self):
        try:
            sim.Stop()
        except:
            pass
        self.enviroment.close()
        if self.__close__window__:
            self.enviroment.close_window()

  
def reward_velocity(x,a,normal=True):
    '''
    a     : avalable
    0.75a : max at x
    0.25a : max at R
    '''
    if x > a or x < 0:
        return -0.01
    R = -a + x + np.sqrt(a**2-a*x)
    if normal:
        return 4 * R / a
    return R

def action_velocity(vel,increase):
    if increase:
        return vel+5
    else:
        if vel < 5:
            return vel/2
        else:
            return vel - 2
        
def nearby_reward_linear(x,R,W):
    return -R/W * x + R if (x > 0 and x < W) else 0