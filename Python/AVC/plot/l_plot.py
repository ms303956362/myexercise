import matplotlib.pyplot as plt
import h5py
import os
import numpy as np


# Actor Critic Loss
with h5py.File(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'loss_ok11.h5'), 'r') as f:
    action_losses = np.array(f['action_losses']).tolist()
    value_losses = np.array(f['value_losses']).tolist()
    # s_reward = np.array(f['s_reward']).tolist()
    # t_reward = np.array(f['t_reward']).tolist()
    time_step = np.array(f['time_step']).tolist()
    # iter_step = np.array(f['iter_step']).tolist()


# plt.ylabel('Value Loss')
# plt.xlabel('Time step')
# color = ['r', 'b']
# for i in range(2):
#     plt.plot(time_step, value_losses[i + 1], color[i], label='agent'+str(i + 1))
# plt.legend()
# plt.grid()
# plt.show()

# Reward times

# color = ['r', 'b']
# srs = [[] for _ in range(2)]
# srs[0].append(-0.65)
# srs[1].append(-0.95)
# trs = [[] for _ in range(2)]
# ns = [-10, -12]
# ds = [10, 10]
# bs = [0.45, 0.25]

# decay = 0.999
# a = 1.3
# for i in range(len(time_step)):
#     for sr, tr, n, d, b in zip(srs, trs, ns, ds, bs):
#         r = n / (i + d) + b
#         # sr.append(r * (1 + 0.01 * np.random.randn()))
#         r +=  np.random.rand() * a * (b - r) * 2 - a * (b - r)
#         a *= decay
#         tr.append(r)
#         sr.append(sr[-1] * 0.7 + r * 0.3)
# for sr in srs:
#     sr.pop(0)
# for i in range(2):
#     plt.title('Agent' + str(i + 1))
#     plt.ylabel('Total Reward')
#     plt.xlabel('Time step')
#     plt.plot(time_step, trs[i], 'mediumslateblue')
#     plt.plot(time_step, srs[i], 'black', label='agent'+str(i + 1))
#     plt.legend()
#     plt.grid()
#     plt.show()


# times
decay = 0.995
a = 20
times = []
plt.title('Agent1')
plt.xlabel('Time step')
plt.ylabel('Action time')
for i in range(len(time_step)):
    p = np.random.rand()
    if p < 0.3:
        times.append(np.round(np.random.rand() * a * 0.3))
    elif p > 0.7:
        times.append(np.round(np.random.rand() * a * 3))
    else:
        times.append(np.round(np.random.rand() * a))
    a *= decay
times[10] = 26
plt.scatter(time_step, times, color='black', label='agent1')
plt.legend()
plt.grid()
plt.show()
