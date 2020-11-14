import matplotlib.pyplot as plt
from typing import Dict
from constant import *


def printResultDict(res: Dict):
    print('\n目标函数值 =', res['cost'], '$')
    print('\n=============================================================================')
    print('|     发电机数据                                                             |')
    print('=============================================================================')
    print('{:^10}\t{:^10}\t{:^10}\t{:^10}\t{:^10}'.format('发电机编号', '节点编号', '有功出力(MW)', '无功出力(MVar)','发电费用($)'), )
    print('{:^10}\t{:^10}\t{:^10}\t{:^10}\t{:^10}'.format('--------------', '--------------', '--------------', '--------------', '--------------'))
    for i in range(res['gen'].shape[0]):
        pg = res['gen'][i, PG]
        cost = res['gencost'][i, COST] * pg ** 2 + res['gencost'][i, COST + 1] * pg + res['gencost'][i, COST + 2]
        print('{:^10d}\t{:^10d}\t{:^10.4f}\t{:^10.4f}\t{:^10.4f}'.format(i + 1, int(res['gen'][i, GEN_BUS]), pg, res['gen'][i, QG], cost))
    
    print('\n=============================================================================')
    print('|     节点数据                                                               |')
    print('=============================================================================')
    print('{:^10}\t{:^10}\t{:^10}\t{:^10}\t{:^10}'.format('节点编号', '电压幅值(pu)', '电压相角(rad)', '有功负荷(MW)', '无功负荷(MVar)'))
    print('{:^10}\t{:^10}\t{:^10}\t{:^10}\t{:^10}'.format('--------------', '--------------', '--------------', '--------------', '--------------'))
    for i in range(res['bus'].shape[0]):
        print('{:^10d}\t{:^10.4f}\t{:^10.4f}\t{:^10.4f}\t{:^10.4f}'.format(int(res['bus'][i, BUS_I]), res['bus'][i, VM], res['bus'][i, VA], res['bus'][i, PD], res['bus'][i, QD]))

    print('\n=============================================================================')
    print('|     支路数据                                                               |')
    print('=============================================================================')
    print('{:^10}\t{:^10}\t{:^10}\t{:^10}\t{:^10}'.format('支路编号', '起始编号', '末端编号', '起始有功(MW)', '末端有功(MW)'))
    print('{:^10}\t{:^10}\t{:^10}\t{:^10}\t{:^10}'.format('--------------', '--------------', '--------------', '--------------', '--------------'))
    for i in range(res['branch'].shape[0]):
        print('{:^10d}\t{:^10d}\t{:^10d}\t{:^10.4f}\t{:^10.4f}'.format(i + 1, int(res['branch'][i, F_BUS]), int(res['branch'][i, T_BUS]), res['branch'][i, ANGMIN], res['branch'][i, ANGMAX]))


def plotGapList(iterList, gapList):
    plt.title('Convergence characteristics of optimal power flow using interior point method')
    plt.xlabel('Iteration times')
    plt.ylabel('Gap')
    plt.yscale('log')
    plt.plot(iterList, gapList, linestyle='--', marker='x', mec='r', c='k', linewidth=1)
    plt.grid(color='lightgrey')
    plt.show()
