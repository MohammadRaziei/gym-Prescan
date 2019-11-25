# -*- coding: utf-8 -*-
"""
Created on Sat May 18 15:47:01 2019

@author: MohammadRaziei
"""

from mygymPrescan.PrescanEnviroment import *
from time import sleep
import numpy as np



class PrescanEnv:
    delay = 0.05  # s

    def __init__(self, enviroment):
        self.enviroment = enviroment
        self.action_space = Discrete(5)
        self.__action__ = np.squeeze(np.zeros((1,self.action_space.n))).tolist()
        self.observation_space = Discrete(13)


        self.__close__window__ = False
        self.reward_function = None
        self.__render__ = 0



    def create(self, car_name=None, road_name=None):
        self.enviroment.create_model(car_name, road_name)

        ##self.Reward.build()

    def reset(self):
        """Resets the state of the environment and returns an initial observation.
        Returns:
            observation (object): the initial observation.
        """
        # sim.Restart()
        self.enviroment.reset()

        start_state = np.squeeze(np.zeros((1,self.observation_space.n))).tolist()
        return start_state

    def step(self, action):
        self.send(action)
        if PrescanEnv.delay > 0 :
            sleep(PrescanEnv.delay)
        self.render()

        car = self.agent
        observation = car['Sensors'][0]['data']['Range'] + [car['data']["Velocity"],car['data']["Position"]["x"], car['data']["Position"]["y"]]
        reward = self.calc_reward()
        done = self.done
        info = {}
        return observation, reward, done, info



    def render(self):
        self.__render__ += 1
        data = self.enviroment.get()
        self.agent = self.enviroment.agent
        self.collision = self.enviroment.collision
        self.time = self.enviroment.data['Time']
        # self.done = bool(self.enviroment.data['done'])
        self.done = self.enviroment.done
        return data

    def calc_reward(self):
        Vel = self.agent['data']['Velocity']
        Longitudinal_reward = reward_velocity(Vel,20)
        Lateral_reward = -0.5  if self.__action__[0] != 0 else 0
        print(self.collision)
        Collision_reward = -10 if self.collision['Occurred'] else 0
        
        reward_T = Longitudinal_reward + Lateral_reward + Collision_reward
        return reward_T

    def seed(self):
        pass

    def send(self,action):
        # action : [-3.5 0 3.5 V 0]
        # action : [0/1  0/1 0/1 V 0/1]
        if len(action) != self.action_space.n:
            raise EnvironmentError
        if action[0] == 1:
            offset = -1
        if action[2] == 1:
            offset = 1
        if action[1] == 1:
            offset = 0
        laneWidth = self.enviroment.road.laneWidth
        offset *= laneWidth
        if action[4] == 1:
            __action__ = self.__action__

        else:
            __action__ =[offset, action[3]]
        
        self.__action__ = __action__
        self.enviroment.send(__action__)


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

  
  
'''
    def action_vec_to_commands(self, action, state):
        off_set = action[0]

        if (action[1] == False) and (action[2] == False):
            desired_velocity = state[1]  # speed is not changed
            throttle_flag = 0
            brake_flag = 0

        elif (action[1] == True) and (action[2] == False):
            # desired_velocity = state[1] + 5
            desired_velocity = 20
            throttle_flag = 1
            brake_flag = 0

        elif (action[1] == False) and (action[2] == True):
            desired_velocity = state[1] - 5
            throttle_flag = 0
            brake_flag = 1

        else:
            raise ("ERROR!")

        # self.off_set_UDP.send(off_set)
        # self.desired_velocity_UDP.send(desired_velocity)
        # self.throttle_flag_UDP.send(throttle_flag)
        # self.brake_flag_UDP.send(brake_flag)
'''


def make(experimant_name):
    set_experimant(experimant_name)
    enviroment = Enviroment(outport=8031,inport=8070)
    enviroment.create_model('Toyota_Yaris_Hatchback_1','StraightRoad_22')
    env = PrescanEnv(enviroment)
    sim.Restart()

    return env



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
        
    

__all__ = ['PrescanEnv','sim','Model']






    # def get_position_road(self,road = None):
    #     __road__ = road if road is not None else self.road
    #     car_x, car_y = self.get_position()
    #     pos_x = car_x -  __road__.position['x']
    #     pos_y = car_y -  __road__.position['y']
    #     self.road_pos = pos_x, pos_y
    #     return self.road_pos

    # def is_in_road(self,road = None):
    #     __road__ = road if road is not None else self.road
    #     pos_x, pos_y = self.get_position_road(__road__)
    #     if abs(pos_y) >= __road__.numberOfLanes * __road__.laneWidth / 2:
    #         return False
    #     if pos_x < 0 or pos_x > __road__.length:
    #         return False
    #     return True

    # def examinLane(self,road = None):
    #     __road__ = road if road is not None else self.road
    #     pos_y = self.get_position_road()[1] / __road__.laneWidth
    #     pos_y_offset = __road__.numberOfLanes / 2
    #     lane = int(np.floor(pos_y) + pos_y_offset)
    #     return lane
