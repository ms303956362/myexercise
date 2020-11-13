import numpy as np
from typing import Dict
from constant import GEN_BUS, PD, QD


def opf_eqcons(x: np.ndarray, Ybus: np.ndarray, ppc: Dict):
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


def opf_ieqcons():
    pass


def dSbus_dV(Ybus: np.ndarray, V: np.ndarray):
    Ibus = Ybus @ V
    diagV = np.diag(V)
    diagIbus = np.diag(Ibus)
    diagVnorm = np.diag(V / np.abs(V))
    dSbus_dVm = diagV @ np.conj(Ybus @ diagVnorm) + np.conj(diagIbus) @ diagVnorm
    dSbus_dVa = 1j * np.diag(V) @ np.conj(diagIbus - Ybus @ diagV)
    return dSbus_dVa.real.T, dSbus_dVa.imag.T, dSbus_dVm.real.T, dSbus_dVm.imag.T



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
