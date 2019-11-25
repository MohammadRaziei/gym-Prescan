import gym
import gym_prescan as gp

# env = gym.make('prescan-without-matlabengine-v0',verbose=True,host='172.21.217.140')
env_dict = {
    'id':       'prescan-without-matlabengine-v0',
    'verbose':  True,
    'host':     '172.21.217.140',
    # 'delay':    2
    'nget':       500
}
env = gym.make(**env_dict)
for _ in range(3):
    env.reset()
    for i in range(3000):
        env.render()
        # env.step(env.action_space.sample()) # take a random action
        n = 200
        a = 3
        if i%n == 0:
            if i%(2*n) == 0:
                a = 0
            else:
                a = 1
        s,r,done, _ = env.step(a)
        if done:
            env.reset()
    # env.close()

    print('+++++++++++++++++++++++++++++++++++++')
# env.reset()
# env.step(5)

