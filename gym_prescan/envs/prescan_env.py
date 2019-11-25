# -*- coding: utf-8 -*-
"""
Created on Sat May 18 15:47:01 2019

@author: MohammadRaziei
"""

import gym
from gym import error, spaces, utils
from gym.utils import seeding

from gym_prescan.envs.PrescanEnviroment import *

from time import sleep
import numpy as np


    
# def Prescan_make(experimant_name):

#     set_experimant(experimant_name)
#     enviroment = Enviroment(outport=8031,inport=8070)
#     enviroment.create_model('Toyota_Yaris_Hatchback_1','StraightRoad_22')
#     env = PrescanEnv(enviroment)
#     sim.Restart()

#     return env



class PrescanEnv(gym.Env):
    def make(self,experimant_name,sim_reset=True):
        set_experimant(experimant_name)
        self.enviroment = Enviroment(outport=8031,inport=8070)
        self.enviroment.create_model('Toyota_Yaris_Hatchback_1','StraightRoad_22')
        if sim_reset:
            sim.Restart()

    def __init__(self, 
                    experimant_name='PreScan_Vissim_Python_0',
                    sim_reset=True,
                    close_window=False,
                    delay=0.05,
                    verbose=False):
        # super(StockTradingEnv, self).__init__()
        self.make(experimant_name,sim_reset)
        super().__init__() 
        self.action_space = spaces.Discrete(6)
        
        self.observation_space = spaces.Box(low=0, high=255, shape= (1, 39), dtype=np.float16)
        self.__close__window__ = close_window
        self.delay = delay #s
        self.verbose = verbose
        
        self.__action__ = [0, 0]
        print('Enviroment is created')




    def create(self, car_name=None, road_name=None):
        self.enviroment.create_model(car_name, road_name)

        ##self.Reward.build()

    def reset(self):
        """Resets the state of the environment and returns an initial observation.
        Returns:
            observation (object): the initial observation.
        """
        # sim.Restart()
        if self.verbose:
            print("env.reset")
        self.enviroment.reset()
        start_state = self._next_observation()
        return start_state

    def step(self, action):
        if self.verbose:
            print("env.step")
        self.send(action)
        if self.delay > 0 :
            sleep(self.delay)
        self.render()

        observation = self._next_observation()
        reward = self.calc_reward()
        done = self.done
        info = {}
        return observation, reward, done, info



    def render_(self):
        data = self.enviroment.get()
        self.agent = self.enviroment.agent
        self.collision = self.enviroment.collision
        self.time = self.enviroment.data['Time']
        # self.done = bool(self.enviroment.data['done'])
        self.done = self.enviroment.done
        return data
    
    def render(self):
        if self.verbose:
            print("env.render")
        self.render_()

    def calc_reward(self):
        Vel = self.agent['data']['Velocity']
        Longitudinal_reward = reward_velocity(Vel,20)
        Lateral_reward = -0.5  if self.__action__[0] != 0 else 0
        Collision_reward = -10 if self.collision['Occurred'] else 0
        
        reward_T = Longitudinal_reward + Lateral_reward + Collision_reward
        return reward_T

    def seed(self):
        pass

    def send(self,action):
        self.__action__ = self.action_translate(action)
        self.enviroment.send(self.__action__)

    def _next_observation(self):
        self.render_()
        obs = np.zeros((1,36),dtype=np.float)
        theta = self.agent['Sensors'][0]['data']['theta']
        Range = self.agent['Sensors'][0]['data']['Range']
        car = self.agent

        for i in range(len(theta)):
            t = int((theta[i] + 180 )/10)
            r = Range[i]
            if obs[0,t] != 0:
                obs[0,t] > r
                continue
            obs[0,t] = r

        extra = [car['data']["Velocity"], car['data']["Position"]["x"], car['data']["Position"]["y"]]
        return np.append(obs, extra)
        

    def action_translate(self,action):
        # Get the data points for the last 5 days and scale to between 0-1
        # Append additional data and scale each value to between 0-1
        lanewidth = self.enviroment.road.laneWidth
        # vel = self.__action__[1]
        vel = self.agent['data']['Velocity']
        offset = self.__action__[0]
        if action == 0 :
            offset = -1
        if action == 1 :
            offset = 0 
        if action == 2 :
            offset = 1
        offset *= lanewidth
        if action == 3 :
            vel += 0.5
        if action == 4 :
            vel -= 0.5

        self.__action__ = [offset,vel]
        print(self.__action__)
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
            sim.Close_window()

  
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
        
    