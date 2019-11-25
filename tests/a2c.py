import gym
import gym_prescan as gp


from stable_baselines.common.policies import MlpPolicy
# from stable_baselines.common.vec_env import SubprocVecEnv
from stable_baselines.common.vec_env import DummyVecEnv

from stable_baselines import A2C

save_load = "a2c_prescan_50000"
env_dict = {
    'id':       'prescan-without-matlabengine-v0',
    'host':     '172.21.217.140',
    'verbose':   True,
    'nget':      150
}


# multiprocess environment
# n_cpu = 4
# env = SubprocVecEnv([lambda: gym.make(**env_dict) for i in range(n_cpu)])

env = gym.make(**env_dict)
env = DummyVecEnv([lambda: env])

model = A2C(MlpPolicy, env, verbose=1, gamma= 0.8)
try:
    model.learn(total_timesteps=25000)
except:
    print('Error!')
model.save(save_load)
# del model # remove to demonstrate saving and loading
'''

model = A2C.load(save_load)

obs = env.reset()
while True:
    print('-----------TEST----------')
    action, _states = model.predict(obs)
    obs, rewards, dones, info = env.step(action)
    env.render()

'''