# -*- coding: utf-8 -*-

# 这是复杂度为 O(n^3) 的蛮力程序
# 你可以把 `test.cmd` 里的 `python std.py` 换成自己写的用于对拍的蛮力程序的启动命令，例如 `force.exe`

# 兼容 Python 2 的 print 语句
from __future__ import print_function

# 兼容 Python 2 的 raw_input 函数
try:
    input = raw_input
except NameError:
    pass

# 读入
n = int(input())                # input() 是读入一行，返回值类型是字符串，然后用 `int' 函数转成整数类型
orders = [[], [], []]
for i in range(3):
    orders[i] = [int(x) for x in input().split()]
k = int(input())

# 计算
selected = []                   # 用于记录已被选取的队员

p = 0                           # 首先由第 0 个教练选队员
for _ in range(n):
    for x in orders[p]:         # 按下标顺序依次遍历 orders[p] 里的每一个元素
        if x not in selected:   # `in' 表示元素在集合里
            selected.append(x)  # python 里数组的 append 相当于 STL 里 vector 的 push_back
            break
    if x == k:
        break
    p = (p + 1) % 3             # 计算接下来由哪个教练选队员

# 输出
print('ABC'[p])
