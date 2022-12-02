n = int(input())
a = [int(x) for x in input().split()]
if n < 3:
    print(0)
else:
    ans = 0
    cnt = {}
    cnt[3 * a[n - 2] - a[n - 1]] = 1
    for i in range(n - 3, -1, -1):
        if a[i] in cnt:
            ans += cnt[a[i]]
        for j in range(i + 1, n):
            if 3 * a[i] - a[j] not in cnt:
                cnt[3 * a[i] - a[j]] = 1
            else:
                cnt[3 * a[i] - a[j]] += 1
    print(ans)
