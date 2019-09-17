import gym
import gym_prescan as gp

env = gym.make('prescan-without-matlabengine-v0',verbose=True)



env.reset()
for _ in range(100):
    env.render()
    # env.step(env.action_space.sample()) # take a random action
    print(env.step(3))
# env.close()

print('+++++++++++++++++++++++++++++++++++++')

for _ in range(100):
    env.render()
    # env.step(env.action_space.sample()) # take a random action
    print(env.step(5))
# env.close()

