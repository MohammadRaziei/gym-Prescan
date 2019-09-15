import socket
import struct, json
import random
import numpy as np
from datetime import datetime


# import torch
# print (torch.cuda.is_available())

class Q_network:

    def __init__(self, name):
        self.name = name

    def feed(self, state):
        best_action = []

        # Neural network out put is the Q-values for all available actions.
        # All available actions are 9 actions; Each of them is a vector of 3 values : [off_set, speed_up, speed_down]
        # We need to select the action with max Q-value
        # Assume this action is a4 = [3.5, True, False]
        # ran = 1
        ran = random.randint(-2, 3)
        best_action = [(3.5 * ran), True, False]
        print(best_action)
        return best_action


def action_vec_to_commands(action, state):
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
        print("ERROR!")

    off_set_UDP.send_data(off_set)
    desired_velocity_UDP.send_data(desired_velocity)
    throttle_flag_UDP.send_data(throttle_flag)
    brake_flag_UDP.send_data(brake_flag)


def get_state_from_data(data):
    state = []
    for i in traffic:
        x = data["Position"]["x"]
        v = data["Velocity"]
        state.append(x)
        state.append(v)
        print(i.name, "position: ", x)
        print(i.name, "speed: ", v, end="\n\n")
    return state


if __name__ == '__main__':

    main_Q_Network = Q_network("mainQN")

    # Creating traffic
    traffic = []
    host = vehicle("host", 8084, 8085)
    host.create()
    traffic.append(host)

    # Reward = Reciver_UDP("Reward", 8081)
    # Reward.build()

    # SimTime = Reciver_UDP("SimTime", 8020)
    # SimTime.build()

    # Creating UDP to recive data from PreScan:
    Get_info_env = Reciver_UDP2("Get_info_env", 8031)
    Get_info_env.build()

    # Creating UDP_ports to send the command of actions:
    off_set_UDP = Transmitter_UDP("off_set", 8072)
    desired_velocity_UDP = Transmitter_UDP("desired_velocity", 8073)
    throttle_flag_UDP = Transmitter_UDP("throttle_flag", 8074)
    brake_flag_UDP = Transmitter_UDP("brake_flag", 8075)

    a = [0, False, False]
    print("initial action: ", a)
    Replay_memory = []
    i = 0
    timeVector = []

    while 1:

        experience = np.array([])

        print("________________________________")
        print("Iteration #", i)
        i = i + 1

        # AIR Data UDP2
        data = Get_info_env.get()

        I = np.zeros(10)
        R = np.zeros(10)
        V = np.zeros(10)
        H = np.zeros(10)
        Current_time = data["Time"]
        I[0] = data["I001"]
        R[0] = data["R001"]
        V[0] = data["V001"]
        H[0] = data["H001"]
        I[1] = data["I002"]
        print("Time: ", data["Time"])
        print("ID:", I[0], " range:", R[0], " vel:", V[0], " head:", H[0])
        print("ID:", I[1])
        print("----------")

        print("if Colide:", int(data["if_collide"]))
        if int(data["if_collide"]) == 1:
            print(" **************** crashh ***************")

        # state
        state = get_state_from_data(data)
        # experience.append(state)
        experience = np.append(experience, state)

        # action
        action_vec = main_Q_Network.feed(state)
        # experience.append(action_vec)
        experience = np.append(experience, action_vec)

        # sendig commands to PreScan
        action_vec_to_commands(action_vec, state)

        # reward
        # r = Reward.get_data()
        r = data["Reward"]

        # experience.append(r)
        experience = np.append(experience, r)

        # next state
        data = Get_info_env.get()
        next_state = get_state_from_data(data)

        # next_state = get_state()
        # experience.append(next_state)
        experience = np.append(experience, next_state)

        print("Experience: ", experience)
        # print("Experience_shape:", experience.shape())
        Replay_memory.append(experience)

        time = datetime.now().time()
        print("Time:", time)
        timeVector.append(time)








































