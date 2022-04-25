import scipy

n, d, e = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(e):
    u, v = map(int, input().split())
    g[u - 1].append(v - 1)
    g[v - 1].append(u - 1)
w = [0 for _ in range(n)]
c = [0 for _ in range(n)]
for _ in range(d):
    wi, ci, pi = map(int, input().split())
    w[pi - 1] = wi
    c[pi - 1] = ci
m = int(input())
k = [0 for _ in range(n)]
for _ in range(m):
    ki, gi = map(int, input().split())
    k[gi - 1] = ki
