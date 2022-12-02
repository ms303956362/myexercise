import math
e = math.e
x = int(input())
n1 = math.floor(x / e)
n2 = math.ceil(x / e)
if (x / n1) ** n1 > (x / n2) ** n2:
    g = math.gcd(x, n1)
    print(int((x / g) ** n1), int((n1 / g) ** n1))
else:
    g = math.gcd(x, n2)
    print(int((x / g) ** n2), int((n2 / g) ** n2))
