#include <cstdio>
#include "Vector.h"


class Point {
public:
    int x;
    int y;
    Point(int px = 0, int py = 0) : x(px), y(py){};
};

bool operator<=(Point &p1, Point &p2) {
    return p1.x <= p2.x;
}

long long merge(Vector<int> &v, Rank lo, Rank mi, Rank hi){
    Vector<int> vl(v, lo, mi);
    int ll = mi - lo, lr = hi - mi;
    long long cnt = 0;
    for (int i = 0, j = 0, k = 0; j < ll;) {
        if (k >= lr || vl[j] <= v[mi + k]) {
            v[lo + i++] = vl[j++];
            cnt += lr - k;
        }
        else {
            v[lo + i++] = v[mi + k++];
        }
    }
    return cnt;
}

long long mergeSort(Vector<int>& v, Rank lo, Rank hi) {
    if (hi - lo < 2)
        return 0;
    Rank mi = (lo + hi) / 2;
    long long cnt_l = mergeSort(v, lo, mi);
    long long cnt_r = mergeSort(v, mi, hi);
    return cnt_l + cnt_r + merge(v, lo, mi, hi);
}

int main(int argc, char const *argv[])
{
    Vector<Point> v;
    int n;
    int px, py;
    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%d %d", &px, &py);
        Point pt(px, py);
        v.insert(pt);
    }
    v.sort();
    Vector<int> vy;
    for (int i = 0; i != v.size(); ++i) {
        vy.insert(v[i].y);
    }
    long long num = mergeSort(vy, 0, vy.size());
    printf("%lld", num);
    return 0;
}
