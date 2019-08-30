# -*- coding: utf-8 -*-
"""
Created on Sat May 18 15:47:01 2019

@author: MohammadRaziei
"""

from myPrescanEnviroment import *

class Env:
    delay = 0.05  # s

    def __init__(self, enviroment): #, off_set_port=None, desired_velocity_port=None, throttle_flag_port=None, brake_flag_port=None):
        # self.road = Road(road_name)
        # self.car = Vehicle(car_name, self.road)
        ##self.Reward = Reciver_UDP(reward_port)

        # Creating UDP_ports to send the command of actions:
        ##self.off_set_UDP = Transmitter_UDP(off_set_port)  # 8072)
        ##self.desired_velocity_UDP = Transmitter_UDP(desired_velocity_port)  # 8073)
        # self.throttle_flag_UDP = Transmitter_UDP(throttle_flag_port)  # 8074)
        # self.brake_flag_UDP = Transmitter_UDP(brake_flag_port)  # 8075)
        self.enviroment = enviroment
        self.action_space = Discrete(3)

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
        self.render()
        start_state = [self.object['data']['Position']["x"], 0]
        return start_state

    def step(self, action):
        sleep(Env.delay)

        car_data = 5#self.car.data.get()
        observation = 5#[car_data["Position"]["x"], car_data["Position"]["y"]]
        reward = 5#self.Reward.get()
        done = False
        info = ''
        return observation, reward, done, info

    def __del__(self):
        self.close()

    def close(self):
        try:
            sim.Stop()
        except:
            pass
        self.enviroment.close()
        sim.Close_window()

        # print('Env-------close')


    def render(self):
        data = self.enviroment.get()
        self.object = self.enviroment.object
        self.time = self.enviroment.data['Time']
        return data


    def seed(self):
        pass

    @staticmethod
    def __get_state__():
        state = []
        for i in Vehicle.__shared_flags__['objects']:
            data = i.data.get()
            x = data["Position"]["x"]
            v = data["Velocity"]["x"]
            state.append(x)
            state.append(v)
            print("Time: ", data["Time"])
            print(i.name, "position: ", x)
            print(i.name, "speed: ", v, end="\n\n")
        return state

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


def make(experimant_name):
    set_experimant(experimant_name)
    '''
    env = Env(car_name='Toyota_Yaris_Hatchback_1', car_port=8091,
                      reward_port=8081,
                      road_name='StraightRoad_1',
                      off_set_port=8072, desired_velocity_port=8073, throttle_flag_port=8074, brake_flag_port=8075
                      )
    '''
    enviroment = Enviroment(outport=8031,inport=(8072,8073,8075))
    enviroment.create_model('Toyota_Yaris_Hatchback_1','StraightRoad_22')
    env = Env(enviroment)
    sim.Restart()

    return env

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
