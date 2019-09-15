import mygymPrescan as gym
from datetime import datetime
from pprint import pprint


def main():
    env = gym.make('PreScan_Vissim_Python_0')
    # env.__close__window__ = True
    # gym.sim.Restart()
    env.delay = 0

    start_state = env.reset()
    state = start_state
    print('done')
    for j in range(2):
        # env.reset()
        for i in gym.time_range(10):
            # env.render()
            # env.enviroment.send([0,15])
            # print(env.enviroment.out.get_str())
            action = [0, 1, 0, 15, 0]
            s, r, done, _ = env.step(action)

            print('_________\n{}.{} - Time : {}'.format(j+1,i+1,env.time))
            print('  state = {}\n  reward = {}\n  done = {}'.format(s,r,done))
            if done:
                break
            
        state = env.reset()
        print('+++++++++++++++++++++++++++++++++++++++++++++++++++++')

    # for i in gym.time_range(1):
    #     env.render()
    #     env.enviroment.send((0,15))
    #     print('_________\n3.{} - Time : {}'.format(i+1,env.time))

    # # gym.sim.Stop()
    # print(gym.Model.objects)
    # env.close()











'''
class Q_network:
    # Set learning parameters
    lr = .8
    y = .95
    num_episodes = 2000

    def __init__(self, env):
        self.env = env
        # Initialize table with all zeros
        self.Q = np.array([env.observation_space.n, env.action_space.n])
        self.index = 0

    def feed(self, state):
        best_action = []

        # Neural network out put is the Q-values for all available actions.
        # All available actions are 9 actions; Each of them is a vector of 3 values : [off_set, speed_up, speed_down]
        # We need to select the action with max Q-value
        # Assume this action is a4 = [3.5, True, False]
        # ran = 1
        ran = random.randint(-2, 3)
        laneWidth = env.car.road.laneWidth
        best_action = [(laneWidth * ran), True, False]
        print(best_action)
        return best_action

    def feed2(self, state, episode_num=1):
        # create lists to contain total rewards and steps per episode
        # jList = []

        self.epoch = episode_num
        # Choose an action by greedily (with noise) picking from Q table
        self.action = np.argmax(
            self.Q[self.state, :] + np.random.randn(1, self.env.action_space.n) * (1. / (self.epoch + 1)))
        return self.action

    def update(self, reward,next_state):
        # Update Q-Table with new knowledge
        self.reward = reward
        self.Q[self.state, self.action] = self.Q[self.state, self.action] + Q_network.lr * (
                    self.reward + Q_network.y * np.max(self.Q[next_state, :]) - self.Q[self.state, self.action])

'''
'''
def reset_environment():

    car_pose_reset.send(1)
    car_speed_reset.send(1)
    other1_pose_reset.send(1)
    other1_speed_reset.send(1)
'''


if __name__ == '__main__':
    main()

    '''
    env = make('cameraCar')
    QNet = Q_network(env)
    # Creating enviroment

    a = [0, False, False]
    print("initial action: ", a)
    Replay_memory = []
    i = 0
    timeVector = []

    start_state = env.reset()


    lr = Q_network.lr
    y = Q_network.y
    num_episodes = Q_network.num_episodes
    rList = []
    for i in range(num_episodes):
        print("________________________________")
        print("Iteration #", i)
        # Reset environment and get first new observation
        state = env.reset()
        rAll = 0
        done = False
        j = 0
        # The Q-Table learning algorithm
        while j < 99:
            j += 1
            action = QNet.feed2(state, i)
            # Get new state and reward from environment
            next_state, reward, done, _ = env.step(action)
            print()
            QNet.update(state)
            rAll += reward * y
            state = next_state
            if done:
                break
        # jList.append(j)
        rList.append(rAll)

    print("Score over time: " + str(sum(rList) / num_episodes))

    print("Final Q-Table Values")
    print(Q)
    '''
