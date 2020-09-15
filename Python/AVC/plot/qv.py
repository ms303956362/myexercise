import matplotlib.pyplot as plt
import numpy as np
from pypower.api import runpf, runopf, ppoption, case39
from pypower.idx_bus import PD, QD, VM, VA
from pypower.idx_gen import PG, QG, VG

ppc = case39()
ppc0 = case39()
ppopt = ppoption(OUT_ALL=0, VERBOSE=0)
res1, _ = runpf(ppc, ppopt)

pers0 = np.array([0.85, 0.75, 0.7, 0.78, 1.1, 1.3, 1.35, 1.3, 1.28, 1.28, 1.25, 1.25, 1.2, 1.18, 1.15, 1, 0.85])
days = 0.8 + 0.15 * np.random.randn(31)
days = sorted(days)

plt.rcParams['font.sans-serif']=['SimSun']
plt.title('12月距发电机不同距离节点的电压变化曲线')
plt.xlabel('时刻')
plt.ylabel('电压标幺值 / p.u.')
for k in [31, 9, 10, 11]:
    pers = pers0
    # cnt = 0
    x = []
    y = []
    for i in range(len(pers) - 1):
        len_i = 96 // (len(pers) - 1)
        for j in range(len_i):
            per = pers[i] + (pers[i+1] - pers[i]) / len_i * j * (1 + 0.1 * np.random.randn())
            ppc['bus'][:, [PD, QD]] = ppc0['bus'][:, [PD, QD]] * per
            ppc['gen'][:, [PG]] = ppc0['gen'][:, [PG]] * per
            res, _ = runpf(ppc, ppopt)
            # cnt += np.sum(res['gen'][:, QG] < 0)
            x.append((len_i * i + j) / 4)
            y.append(np.sum(res['bus'][k, VM]))
    # print(str(k) + ': ' + str(cnt / 960 * 100) + '%')
    plt.plot(x, y, label='节点'+str(k + 1))
    print('节点'+str(k + 1) + ': '+ str(np.std(y)))
    # if k == 3 or k == 9 or k == 16 or k == 27:
    #     plt.plot(x, y, color='black')
    # else:
    #     plt.plot(x, y, dashes=[6, 2], color='gray')
plt.legend()
plt.show()
