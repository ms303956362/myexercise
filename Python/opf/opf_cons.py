import numpy as np
from typing import Dict
from constant import GEN_BUS, PD, QD, F_BUS
from derivatives import dSbus_dV, dSbr_dV


def opf_eqcons(x: np.ndarray, Ybus: np.ndarray, ppc: Dict):
    '''
    等式约束及其雅可比矩阵
    输入参数：
        x:      状态变量 {Pg, Qg, theta, Vm}
        Ybus:   节点导纳矩阵
        ppc：   标准case
    返回：
        h:      等式约束在状态变量为x时的值
        dh：    等式约束雅克比矩阵在状态变量x时的值
    '''
    bus, gen, branch = ppc["bus"], ppc["gen"], ppc["branch"]
    # 维数
    nx = x.shape[0]
    nb = bus.shape[0]
    nl = branch.shape[0]
    ng = gen.shape[0]
    
    # 状态变量
    pg = x[0 : ng]
    qg = x[ng : 2 * ng]
    theta = x[2 * ng: 2 * (ng + nb) - 1 : 2]
    vm = x[2 * ng + 1: 2 * (ng + nb) : 2]
    V = vm * np.exp(1j * theta)

    # 等式约束
    idx_g = gen[:, GEN_BUS].astype(int) - 1     # 下标从0开始
    
    ## 等式约束误差
    h = np.zeros(2 * nb)
    h[idx_g * 2] = pg
    h[idx_g * 2 + 1] = qg
    Sbus = V * np.conj(Ybus @ V)
    h[np.arange(nb) * 2] -= bus[:, PD] + Sbus.real
    h[np.arange(nb) * 2 + 1] -= bus[:, QD] + Sbus.imag

    ## 等式约束雅可比矩阵
    dh = np.zeros((2 * (ng + nb), 2 * nb))
    dh[np.arange(ng), idx_g * 2] = 1     ## dh/dpg
    dh[np.arange(ng, 2 * ng), idx_g * 2 + 1] = 1     ## dh/dqg
    dp_dva, dq_dva, dp_dvm, dq_dvm = dSbus_dV(Ybus, V)
    dh[2 * ng : 2 * (ng + nb) : 2, :][:, 0 : 2 * nb : 2] = -dp_dva
    dh[2 * ng : 2 * (ng + nb) : 2, :][:, 1 : 2 * nb : 2] = -dq_dva
    dh[2 * ng + 1 : 2 * (ng + nb) : 2, :][:, 0 : 2 * nb : 2] = -dp_dvm
    dh[2 * ng + 1 : 2 * (ng + nb) : 2, :][:, 1 : 2 * nb : 2] = -dq_dvm
    
    return h, dh


def opf_ieqcons(x: np.ndarray, Yf: np.ndarray, ppc: Dict):
    '''
    不等式约束及其雅可比矩阵
    输入参数：
        x:      状态变量 {Pg, Qg, theta, Vm}
        Yf:     支路导纳矩阵
        ppc：   标准case
    返回：
        g:      不等式约束在状态变量为x时的值
        dg：    不等式约束雅克比矩阵在状态变量x时的值
    '''
    bus, gen, branch = ppc["bus"], ppc["gen"], ppc["branch"]
    # 维数
    nx = x.shape[0]
    nb = bus.shape[0]
    nl = branch.shape[0]
    ng = gen.shape[0]
    
    # 状态变量
    pg = x[0 : ng]
    qg = x[ng : 2 * ng]
    theta = x[2 * ng: 2 * (ng + nb) - 1 : 2]
    vm = x[2 * ng + 1: 2 * (ng + nb) : 2]
    V = vm * np.exp(1j * theta)

    # 不等式约束
    Sf = V[branch[:, F_BUS].astype(int) - 1] * np.conj(Yf @ V)
    g = np.zeros(2 * ng + nb + nl)
    g[0 : ng] = pg
    g[ng : 2 * ng] = qg
    g[2 * ng : 2 * ng + nb] = vm
    g[2 * ng + nb: 2 * ng + nb + nl] = Sf.real

    # 不等式约束雅可比矩阵
    dg = np.zeros((2 * (ng + nb), 2 * ng + nb + nl))
    dg[0 : ng, :][:, 0 : ng] = np.eye(ng)       # dpg / dpg
    dg[ng : 2 * ng, :][:, ng : 2 * ng] = np.eye(ng)     # dqg / dqg
    dg[2 * ng + 1 : 2 * (ng + nb) : 2, 2 * ng : 2 * ng + nb] = np.eye(nb)    # dv / dv
    dp_dva, _, dp_dvm, _ = dSbr_dV(branch, Yf, V)
    dg[2 * ng : 2 * (ng + nb) : 2, :][:, (2 * ng + nb) : (2 * ng + nb + nl)] = dp_dva
    dg[2 * ng + 1: 2 * (ng + nb) : 2, :][:, (2 * ng + nb) : (2 * ng + nb + nl)] = dp_dvm

    return g, dg


if __name__ == "__main__":
    from makeYbus import makeYbus
    from case5 import case5
    from constant import PMAX, PMIN, QMAX, QMIN
    ppc = case5()
    Ybus, Yf, Yt = makeYbus(ppc['baseMVA'], ppc['bus'], ppc['branch'])
    bus, gen, branch = ppc["bus"], ppc["gen"], ppc["branch"]
    nb = bus.shape[0]
    ng = gen.shape[0]
    x = np.zeros(2 * (ng + nb))
    x[0 : ng] = (gen[:, PMAX] + gen[:, PMIN]) / 2
    x[ng : 2 * ng] = (gen[:, QMAX] + gen[:, QMIN]) / 2
    x[2 * ng : 2 * (ng + nb) : 2] = 0
    x[2 * ng + 1: 2 * (ng + nb) : 2] = 1
    x[-1] = 1.05
    h, dh = opf_eqcons(x, Ybus, ppc)
    g, dg = opf_ieqcons(x, Yf, ppc)
