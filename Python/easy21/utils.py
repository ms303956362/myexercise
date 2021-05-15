import numpy as np
import matplotlib.pyplot as plt
from constants import DEALER_MAX_SHOW_SCORE, BUST_MIN_SCORE, BUST_MAX_SCORE


def plot_value_function(v_table: dict):
    xx = np.arange(BUST_MIN_SCORE, DEALER_MAX_SHOW_SCORE + 1)
    yy = np.arange(BUST_MIN_SCORE, BUST_MAX_SCORE + 1)
    x, y = np.meshgrid(xx, yy)
    z = np.zeros_like(x, dtype=float)
    for i in range(len(yy)):
        for j in range(len(xx)):
            z[i][j] = v_table[(y[i][j], x[i][j])]
    plt.figure()  #定义新的三维坐标轴
    ax3 = plt.axes(projection='3d')
    ax3.plot_surface(x, y, z, cmap='rainbow')
    plt.show()


def plot_mse(lmbdas, mse):
    plt.figure()
    plt.plot(lmbdas, mse)
    plt.show()

def plot_mses(lmbdas, mses):
    plt.figure()
    for lmbda, mse in zip(lmbdas, mses):
        plt.plot(np.arange(len(mse)), mse, label=str(lmbda))
    plt.legend()
    plt.show()
