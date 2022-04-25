import random

t = 10
n = 5
l = [str(i) for i in range(1, n + 1)] + [str(i) for i in range(1, n + 1)]

print(t)
for i in range(t):
    random.shuffle(l)
    print(n)
    print(" ".join(l))
