import matplotlib.pyplot as plt
import h5py
import os
import numpy as np

with h5py.File(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'loss.h5'), 'r') as f:
    action_losses = np.array(f['action_losses']).tolist()
    value_losses = np.array(f['value_losses']).tolist()
    s_reward = np.array(f['s_reward']).tolist()
    t_reward = np.array(f['t_reward']).tolist()
    time_step = np.array(f['time_step']).tolist()
    iter_step = np.array(f['iter_step']).tolist()

num = 1
for al in action_losses:
    plt.subplot(3, 3, num)
    plt.plot(time_step, al)
    num += 1
for vl in value_losses:
    plt.subplot(3, 3, num)
    plt.plot(time_step, vl)
    num += 1
for sl, tl in zip(s_reward, t_reward):
    plt.subplot(3, 3, num)
    plt.plot(iter_step, sl)
    plt.plot(iter_step, tl)
    num += 1
plt.savefig(str(num))
plt.show()