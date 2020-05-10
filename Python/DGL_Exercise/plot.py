import matplotlib.pyplot as plt
import numpy as np
rmse_list = np.array([86.04709826680248, 64.93343131623438, 62.903856705309806, 33.83745008673128, 29.10302921318079, 29.801280813143247, 25.871515800034224, 30.505347757407772, 34.42741123448539, 23.834317670557123, 29.50524823501056, 28.995016724995725, 26.733689378691718, 25.226968702774048, 23.272196079892666])
plt.rcParams['font.sans-serif'] = ['STSong']
plt.figure()
plt.grid(linestyle='-.')
x = np.log10(np.array([0.00001, 0.00005, 0.0001, 0.0003, 0.001, 0.003, 0.01, 0.1, 0.11, 0.115, 0.12, 0.125, 0.3, 1]))
y = [26.45641, 12.4339, 10.67962, 7.63968, 4.59395,  3.83136, 2.17679, 2.40603, 3.559786, 2.60510, 7.885317, 25.56, 27.68, 28.59]
plt.plot(x, y)
# plt.plot((np.array(range(len(rmse_list)))  + 1 ) * 20, rmse_list / 10)
plt.tick_params(labelsize=20)
plt.xlabel('学习率取以10为底的对数', fontsize=20)
plt.ylabel('均方根误差 / MW', fontsize=20)
plt.savefig('lr.png', bbox_inches='tight')
plt.show()
