import gym
import gym_prescan

from stable_baselines import GAIL, SAC
from stable_baselines.gail import ExpertDataset, generate_expert_traj


save_load = "gail_prescan"
env_dict = {
    'id':       'prescan-without-matlabengine-v0',
    'verbose':  True,
    'host':     '172.21.217.140',
    'nget':       150
}

env = gym.make(**env_dict)


# Generate expert trajectories (train expert)
model = SAC('MlpPolicy', env, verbose=1)
generate_expert_traj(model, 'expert_prescan', n_timesteps=100, n_episodes=10)

# Load the expert dataset
dataset = ExpertDataset(expert_path='expert_prescan.npz', traj_limitation=10, verbose=1)

model = GAIL("MlpPolicy", env, dataset, verbose=1)
# Note: in practice, you need to train for 1M steps to have a working policy
try:
    model.learn(total_timesteps=1000)
except:
    pass
model.save(save_load)
'''
del model # remove to demonstrate saving and loading

model = GAIL.load(save_load)

env = gym.make(**env_dict)
obs = env.reset()
while True:
  action, _states = model.predict(obs)
  obs, rewards, dones, info = env.step(action)
  env.render()
  '''