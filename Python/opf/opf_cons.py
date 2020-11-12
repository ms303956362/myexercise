from typing import Dict
import numpy as np


GEN_BUS = 0
PD = 2
QD = 3


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
    idx_g = gen[:, GEN_BUS] - 1     # 下标从0开始
    
    ## 等式约束误差
    h = np.zeros(2 * nb)
    h[idx_g * 2] = pg
    h[idx_g * 2 + 1] = qg
    Sbus = V * np.conj(Ybus * V)
    h[np.arange(nb) * 2] -= bus[:, PD] + Sbus.real
    h[np.arange(nb) * 2 + 1] -= bus[:, QD] + Sbus.imag

    ## 等式约束雅可比矩阵
    dh = np.zeros((2 * (ng + nb), 2 * nb))
    dh[np.arange(ng), idx_g * 2] = 1     ## dh/dpg
    dh[np.arange(ng, 2 * ng), idx_g * 2 + 1] = 1     ## dh/dqg
    dp_dva, dq_dva, dp_dvm, dq_dvm = dSbus_dV(Ybus, V)
    dh[np.arange(2 * ng, 2 * (ng + nb), 2), np.arange(2 * ng, 2 * (ng + nb), 2)] = -dp_dva
    dh[np.arange(2 * ng, 2 * (ng + nb), 2), np.arange(2 * ng + 1, 2 * (ng + nb), 2)] = -dq_dva
    dh[np.arange(2 * ng + 1, 2 * (ng + nb), 2), np.arange(2 * ng, 2 * (ng + nb), 2)] = -dp_dvm
    dh[np.arange(2 * ng + 1, 2 * (ng + nb), 2), np.arange(2 * ng + 1, 2 * (ng + nb), 2)] = -dq_dvm
    
    return h, dh





def dSbus_dV(Ybus: np.ndarray, V: np.ndarray):
    Ibus = Ybus @ V
    diagV = np.diag(V)
    diagIbus = np.diag(Ibus)
    diagVnorm = np.diag(V / np.abs(V))
    dSbus_dVm = diagV @ np.conj(Ybus @ diagVnorm) + np.conj(diagIbus) @ diagVnorm
    dSbus_dVa = 1j * np.diag(V) @ np.conj(diagIbus - Ybus @ diagV)
    return dSbus_dVa.real, dSbus_dVa.imag, dSbus_dVm.real, dSbus_dVm.imag

