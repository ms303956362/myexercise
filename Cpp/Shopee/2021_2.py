from sortedcollections import SortedList

n, k = map(int, input().split())
a = [int(i) for i in input().split()]
pre = [0 for _ in range(n + 1)]
for i in range(1, n + 1):
    pre[i] = pre[i - 1] + a[i - 1]
s = SortedList()
ans = 0
for i in range(1, n + 1):
    ans += s.bisect_right(pre[i] - k * i)
    s.add(pre[i] - k * i)
print(ans)
