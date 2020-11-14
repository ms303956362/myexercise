import numpy as np
from typing import Dict
from constant import F_BUS


def dSbus_dV(Ybus: np.ndarray, V: np.ndarray):
    '''
    节点注入复功率关于电压相量的导数
    输入参数：
        Ybus:   节点导纳矩阵
        V:      电压相量
    返回：
        dSbus_dVa.real： 节点注入有功功率关于电压相角的导数
        dSbus_dVa.imag： 节点注入无功功率关于电压相角的导数
        dSbus_dVm.real： 节点注入有功功率关于电压幅值的导数
        dSbus_dVm.imag： 节点注入无功功率关于电压幅值的导数
    参考资料：
        http://www.pserc.cornell.edu/matpower/TN2-OPF-Derivatives.pdf
    '''
    Ibus = Ybus @ V
    diagV = np.diag(V)
    diagIbus = np.diag(Ibus)
    diagVnorm = np.diag(V / np.abs(V))
    dSbus_dVm = diagV @ np.conj(Ybus @ diagVnorm) + np.conj(diagIbus) @ diagVnorm
    dSbus_dVa = 1j * np.diag(V) @ np.conj(diagIbus - Ybus @ diagV)
    return dSbus_dVa.real.T, dSbus_dVa.imag.T, dSbus_dVm.real.T, dSbus_dVm.imag.T


def dSbr_dV(branch: Dict, Yf: np.ndarray, V: np.ndarray):
    '''
    支路复功率关于电压相量的导数
    输入参数：
        branch: 标准case中的branch矩阵
        Yf:     支路导纳矩阵
        V:      电压相量
    返回：
        dSf_dVa.real： 支路有功功率关于电压相角的导数
        dSf_dVa.imag： 支路无功功率关于电压相角的导数
        dSf_dVm.real： 支路有功功率关于电压幅值的导数
        dSf_dVm.imag： 支路无功功率关于电压幅值的导数
    参考资料：
        http://www.pserc.cornell.edu/matpower/TN2-OPF-Derivatives.pdf
    '''
    f = branch[:, F_BUS].astype(int) - 1
    nl = len(f)
    nb = len(V)

    Vnorm = V / abs(V)

    If = Yf @ V
    diagVf      = np.diag(V[f])
    diagIf      = np.diag(If)
    diagV       = np.diag(V)
    diagVnorm   = np.diag(Vnorm)
    temp1       = np.zeros((nl, nb), complex)
    temp2       = np.zeros((nl, nb), complex)
    for i in range(nl):
        temp1[i, f[i]] = np.asscalar(V[f[i]])
        temp2[i, f[i]] = np.asscalar(Vnorm[f[i]])

    dSf_dVa = 1j * (np.conj(diagIf) @ temp1 - diagVf @ np.conj(Yf @ diagV))
    dSf_dVm = diagVf @ np.conj(Yf @ diagVnorm) + np.conj(diagIf) @ temp2

    return dSf_dVa.real.T, dSf_dVa.imag.T, dSf_dVm.real.T, dSf_dVm.imag.T


def d2Sbus_dV2(Ybus, V, lam):
    '''
    节点注入复功率关于电压相量的二阶导数
    输入参数：
        Ybus:   节点导纳矩阵
        V:      电压相量
        lam:    等式约束的拉格朗日乘子
    返回：
        Haa： 节点注入功率关于电压相角的二阶偏导数
        Hav： 节点注入功率关于电压相角和电压幅值的混合偏导数
        Hva： 节点注入功率关于电压幅值和电压相角的混合偏导数
        Hvv： 节点注入功率关于电压幅值的二阶偏导数
    参考资料：
        http://www.pserc.cornell.edu/matpower/TN2-OPF-Derivatives.pdf
    '''
    nb = len(V)
    Ibus = Ybus @ V
    diaglam = np.diag(lam)
    diagV = np.diag(V)

    A = diaglam @ diagV
    B = Ybus @ diagV
    C = A @ np.conj(B)
    D = np.conj(Ybus).T @ diagV
    E = np.conj(diagV) @ (D @ diaglam - np.diag(D @ lam))
    F = C - A @ np.diag(np.conj(Ibus))
    G = np.diag(np.ones(nb) / np.abs(V))

    Haa = E + F
    Hva = 1j * G @ (E - F)
    Hav = Hva.T
    Hvv = G @ (C + C.T) @ G

    return Haa, Hav, Hva, Hvv


def d2Sbr_dV2(Cbr, Ybr, V, lam):
    '''
    支路复功率关于电压相量的导数
    输入参数：
        Cbr:    线路与节点之间的关联矩阵
        Ybr:    支路导纳矩阵
        V:      电压相量
        lam:    不等式约束的拉格朗日乘子
    返回：
        Gaa： 支路功率关于电压相角的二阶偏导数
        Gav： 支路功率关于电压相角和电压幅值的混合偏导数
        Gva： 支路功率关于电压幅值和电压相角的混合偏导数
        Gvv： 支路功率关于电压幅值的二阶偏导数
    参考资料：
        http://www.pserc.cornell.edu/matpower/TN2-OPF-Derivatives.pdf
    '''
    nb = len(V)

    diaglam = np.diag(lam)
    diagV = np.diag(V)

    A = np.conj(Ybr).T @ diaglam @ Cbr
    B = np.conj(diagV) @ A @ diagV
    D = np.diag(A @ V) @ np.conj(diagV)
    E = np.diag(A.T @ np.conj(V)) @ diagV
    F = B + B.T
    G = np.diag(np.ones(nb) / abs(V))

    Gaa = F - D - E
    Gva = 1j * G @ (B - B.T - D + E)
    Gav = Gva.T
    Gvv = G @ F @ G

    return Gaa, Gav, Gva, Gvv
