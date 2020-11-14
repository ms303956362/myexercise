import numpy as np
from opf_cons import *
from opf_cost import *
from opf_hess import *
from makeYbus import *
from ips import *
from constant import *
from utils import *
from copy import deepcopy


def opf(ppc, printResult=True, plotGap=False):
    # 系统参数
    bus, gen, branch = ppc["bus"], ppc["gen"], ppc["branch"]
    Ybus, Yf, Yt = makeYbus(ppc['baseMVA'], ppc['bus'], ppc['branch'])
    
    # 维数
    nb = bus.shape[0]
    ng = gen.shape[0]
    nl = branch.shape[0]

    # 初值
    x0 = np.zeros(2 * (ng + nb))
    x0[0 : ng] = (gen[:, PMAX] + gen[:, PMIN]) / 2
    x0[ng : 2 * ng] = (gen[:, QMAX] + gen[:, QMIN]) / 2
    x0[2 * ng : 2 * (ng + nb) : 2] = 0
    x0[2 * ng + 1: 2 * (ng + nb) : 2] = 1
    x0[-1] = 1.05

    # 不等式约束上下限
    gl = np.zeros(2 * ng + nb + nl)
    gu = np.zeros(2 * ng + nb + nl)
    gl[0 : ng] = gen[:, PMIN]
    gl[ng : 2 * ng] = gen[:, QMIN]
    gl[2 * ng : 2 * ng + nb] = bus[:, VMIN]
    gl[2 * ng + nb : 2 * ng + nb + nl] = -branch[:, RATE_A]
    gu[0 : ng] = gen[:, PMAX]
    gu[ng : 2 * ng] = gen[:, QMAX]
    gu[2 * ng : 2 * ng + nb] = bus[:, VMAX]
    gu[2 * ng + nb : 2 * ng + nb + nl] = branch[:, RATE_A]

    # 雅可比矩阵、Hess矩阵
    f_func = lambda x: opf_cost(x, ppc)
    h_func = lambda x: opf_eqcons(x, Ybus, ppc)
    g_func = lambda x: opf_ieqcons(x, Yf, ppc)
    hess_func = lambda x, lmbda: opf_hess(x, lmbda, Ybus, Yf, ppc)

    # 内点法求解
    x, f, iterList, gapList = ips(f_func, h_func, g_func, hess_func, x0, gl, gu, retList=True)
    theta_ref = x[-2]
    x[2 * ng : 2 * (ng + nb) : 2] -= theta_ref

    # 计算支路功率
    pg = x[0 : ng]
    qg = x[ng : 2 * ng]
    theta = x[2 * ng : 2 * (ng + nb) : 2]
    vm = x[2 * ng + 1 : 2 * (ng + nb) : 2]
    V = vm * np.exp(1j * theta)
    Sf = V[branch[:, F_BUS].astype(int) - 1] * np.conj(Yf @ V)
    St = V[branch[:, T_BUS].astype(int) - 1] * np.conj(Yt @ V)
    # 保存结果
    result = deepcopy(ppc)
    result['cost'] = f
    result['gen'][:, PG] = pg
    result['gen'][:, QG] = qg
    result['bus'][:, VM] = vm
    result['bus'][:, VA] = theta
    result['branch'][:, ANGMIN] = Sf.real
    result['branch'][:, ANGMAX] = St.real

    # 打印结果
    if printResult:
        printResultDict(result)
    if plotGap:
        plotGapList(iterList, gapList)
    
    return result


if __name__ == "__main__":
    from case5 import case5
    ppc = case5()
    res = opf(ppc, plotGap=True)
    print(res['cost'])
    print(res['gen'][:, PG])
    print(res['gen'][:, QG])
    print(res['bus'][:, VM])
    print(res['bus'][:, VA])
    print(res['branch'][:, ANGMIN])
    print(res['branch'][:, ANGMAX])
