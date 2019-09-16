import gym
import gym_prescan

env = gym.make('prescan-v0')
s = env.reset()
print(s)
a = 1
s,r,d,_ = env.step(a)
print(s,r,d)