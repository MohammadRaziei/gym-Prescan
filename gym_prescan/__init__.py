# -*- coding: utf-8 -*-
"""
Created on Sat May 18 15:47:01 2019

@author: MohammadRaziei
"""

# from gym_prescan.core import *

from gym.envs.registration import register
'''
register(
    id='prescan-v0',
    entry_point='gym_prescan.envs:PrescanEnv',
    # kwargs={'rows' : 3},
    # tags={'wrapper_config.TimeLimit.max_episode_steps': 200},
    # reward_threshold=25.0,
)
'''
register(
    id='prescan-without-matlabengine-v0',
    entry_point='gym_prescan.envs:PrescanEnv2',
    # kwargs={'rows' : 3},
    # tags={'wrapper_config.TimeLimit.max_episode_steps': 200},
    # reward_threshold=25.0,
)


# __all__ = ['PrescanEnv','sim','Model']



time_step = 0.08
def time_range(t_end,steps=time_step):
    return range(int(t_end/steps))
def time_at(t,steps=time_step):
    return int(t/steps)
    