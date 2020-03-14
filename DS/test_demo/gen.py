# -*- coding: utf-8 -*-

# 这是随机生成测试数据的程序
# 你可以把 `test.cmd` 里的 `python gen.py` 换成自己写的生成测例程序的启动命令，例如 `gen.exe`
# 可以用 C++ 写生成测例程序并编译成 .exe。如果你觉得 python 比 C++ 用起来更方便的话，可以模仿着写一下

# 兼容 Python 2 的 print 语句
from __future__ import print_function

import random

n = random.randrange(5, 10)         # 数据规模 n 取 [5, 10) 的随机数，你在测试时也可以选取更大的 n
print(n)                            # 打印 n，并换行
for _ in range(3):
    a = range(0, n)                 # range(0, n) 是 [0, n) 的迭代器
    line = [str(x + 1) for x in a]  # 把每个整数 x 转成表示 x + 1 的字符串
    random.shuffle(line)            # 随机打乱
    print(' '.join(line))           # 以空格为分隔符，把数组里的字符串拼接起来，再打印出来，并换行
k = random.randrange(1, n + 1)      # 随机选取 [1, n + 1) 范围的 k
print(k)
