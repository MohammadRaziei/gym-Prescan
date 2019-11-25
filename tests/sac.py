import gym, gym_prescan
import numpy as np

from stable_baselines.sac.policies import MlpPolicy
from stable_baselines.common.vec_env import DummyVecEnv
from stable_baselines import SAC

save_load = "sac_prescan_50000"
env_dict = {
    'id':       'prescan-without-matlabengine-v0',
    'host':     '172.21.217.140',
    'verbose':  True,
    'nget':     150
}

env = gym.make(**env_dict)
env = DummyVecEnv([lambda: env])

model = SAC(MlpPolicy, env, verbose=1, gamma=0.8)
try:
    model.learn(total_timesteps=50000, log_interval=10)
except:
    pass
model.save(save_load)

'''
# del model # remove to demonstrate saving and loading

model = SAC.load(save_load)

obs = env.reset()
while True:
    action, _states = model.predict(obs)
    obs, rewards, dones, info = env.step(action)
    env.render()
'''