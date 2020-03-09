#include <cstdio>

class Point {
public:
    int x;
    int y;
};

bool operator<(Point& p, Point& l) { // 直线(a, b)必须在左侧，点(x, y)必须在右侧
    return static_cast<long long>(l.x) * static_cast<long long>(p.y) +
               static_cast<long long>(l.y) * static_cast<long long>(p.x) -
               static_cast<long long>(l.x) * static_cast<long long>(l.y) <
           0;
}

int find(Point* vl, int n, Point& p) {
    int lo = 0, hi = n;
    int mi;
    while (lo != hi) {
        mi = (lo + hi) / 2;
        if (p < vl[mi]) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    return lo;
}

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    int n, m;
    int region;
    scanf("%d %d", &n, &m);
    Point *vl = new Point[n], p;
    for (int i = 0; i != n; ++i) {
        scanf("%d %d", &vl[i].x, &vl[i].y);
    }
    for (int i = 0; i != m; ++i) {
        scanf("%d %d", &p.x, &p.y);
        region = find(vl, n, p);
        if (i == 0) {
            printf("%d", region);
        } else {
            printf("\n%d", region);
        }
    }
    return 0;
}
