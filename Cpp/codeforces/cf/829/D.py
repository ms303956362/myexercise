from collections import Counter


n, x = map(int, input().split())
a = [int(num) for num in input().split()]
cnt = Counter(a)
f = 1
s = 0
for i in range(1, max(a) + 1):
    f *= i
    s += cnt[i] * f
fx = 1
for i in range(1, x + 1):
    fx *= i
if f % fx == 0:
    print('Yes')
else:
    print('No')
