import numpy as np
from typing import Dict
from constant import F_BUS


def dSbus_dV(Ybus: np.ndarray, V: np.ndarray):
    Ibus = Ybus @ V
    diagV = np.diag(V)
    diagIbus = np.diag(Ibus)
    diagVnorm = np.diag(V / np.abs(V))
    dSbus_dVm = diagV @ np.conj(Ybus @ diagVnorm) + np.conj(diagIbus) @ diagVnorm
    dSbus_dVa = 1j * np.diag(V) @ np.conj(diagIbus - Ybus @ diagV)
    return dSbus_dVa.real.T, dSbus_dVa.imag.T, dSbus_dVm.real.T, dSbus_dVm.imag.T


def dSbr_dV(branch: Dict, Yf: np.ndarray, V: np.ndarray):
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
