import gym, gym_prescan

from stable_baselines.common.policies import MlpPolicy, MlpLstmPolicy, MlpLnLstmPolicy
# from stable_baselines.common.vec_env import SubprocVecEnv
from stable_baselines.common.vec_env import DummyVecEnv
from stable_baselines import ACKTR

# multiprocess environment

save_load = "acktr_prescan"
env_dict = {
    'id':       'prescan-without-matlabengine-v0',
    'verbose':  True,
    'host':     '172.21.217.140',
    'nget':       150
}

# n_cpu = 1
# env = SubprocVecEnv([lambda: gym.make('CartPole-v1') for i in range(n_cpu)])

env = gym.make(**env_dict)
env = DummyVecEnv([lambda: env])

'''

model = ACKTR(MlpPolicy, env, verbose=1)
try:
    model.learn(total_timesteps=25000)
except:
    pass
model.save(save_load)
'''
# del model # remove to demonstrate saving and loading

model = ACKTR.load(save_load)

obs = env.reset()
while True:
    print('-----------TEST----------')
    action, _states = model.predict(obs)
    obs, rewards, dones, info = env.step(action)
    env.render()