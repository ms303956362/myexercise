from posixpath import split


n1, n2, n3 = map(int, input().split(' '))
s1, s2, s3 = set(), set(), set()
l = input().split(' ')
for w in l:
    s1.add(w)
l = input().split(' ')
for w in l:
    s2.add(w)
l = input().split(' ')
for w in l:
    s3.add(w)

def check(l):
    cnt1, cnt2, cnt3 = 0, 0, 0
    for w in l:
        if w in s1:
            if cnt2 > 0 or cnt3 > 0:
                return False
            cnt1 += 1
        elif w in s2:
            if cnt3 > 0:
                return False
            cnt2 += 1
        elif w in s3:
            cnt3 += 1
        else:
            raise Exception()
    return cnt1 > 0 and cnt2 == 1

m = int(input())
for i in range(m):
    l = input().split(' ')
    if check(l):
        print('YES')
    else:
        print('NO')
