import random

n = 100
l = []
for _ in range(n):
    l.append(str(random.randint(1, 100)))
with open('test6.in', 'w') as f:
    f.writelines(str(n) + '\n')
    f.writelines(' '.join(l))
