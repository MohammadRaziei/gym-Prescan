import gym, gym_prescan

from stable_baselines.common.policies import MlpPolicy
from stable_baselines.common.vec_env import DummyVecEnv
from stable_baselines import TRPO

save_load = "trpo_prescan"
env_dict = {
    'id':       'prescan-without-matlabengine-v0',
    'verbose':  True,
    'host':     '172.21.217.140',
    'nget':     150
}




env = gym.make(**env_dict)
env = DummyVecEnv([lambda: env])

model = TRPO(MlpPolicy, env, verbose=1)
try:
    model.learn(total_timesteps=50000)
except:
    print('Error!')
    pass
model.save(save_load)
'''
del model # remove to demonstrate saving and loading

model = TRPO.load(save_load)

obs = env.reset()
while True:
    action, _states = model.predict(obs)
    obs, rewards, dones, info = env.step(action)
    env.render()
'''