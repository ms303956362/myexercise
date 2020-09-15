import matplotlib.pyplot as plt
import numpy as np


vb_avg = [1.038, 1.04, 1.042]
va_avg = [0.995, 1.007, 1.015]
n = [
        np.arange(14), 
        np.arange(11),
        np.arange(14)
    ]
vb = [
        0.01 * np.random.randn(14) + vb_avg[0],
        0.01 * np.random.randn(11) + vb_avg[1],
        0.01 * np.random.randn(14) + vb_avg[2]
    ]

va = [
        0.006 * 1 * np.random.randn(14) + va_avg[0],
        0.006 * 1 * np.random.randn(11) + va_avg[1],
        0.005 * 1 * np.random.randn(14) + va_avg[2]
    ]

plt.rcParams.update({"font.size":15})
for i in range(3):
    plt.title('agent' + str(i + 1))
    plt.ylabel('Voltage(pu)')
    plt.xlabel('Bus Index')
    plt.plot(n[i], 1.05 * np.ones(n[i].shape), 'r--', label='boundary')
    plt.plot(n[i], 0.95 * np.ones(n[i].shape), 'r--')
    plt.plot(n[i], vb_avg[i] * np.ones(n[i].shape), 'k--', label='before control')
    plt.plot(n[i], va_avg[i] * np.ones(n[i].shape), 'b--', label='after control')
    plt.scatter(n[i], vb[i], c='gray', s=6, alpha=0.3)
    plt.scatter(n[i], va[i], c='b', s=6, alpha=0.3)
    plt.legend(loc=(5/10, 1/9))
    plt.grid()
    plt.show()
