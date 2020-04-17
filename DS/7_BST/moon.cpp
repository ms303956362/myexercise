#include <cstdio>
#include <cstring>
#include "AVL.h"

struct Bridge{
    int p;
    int v;
    Bridge(int pj = -1, int vj = -1) : p(pj), v(vj) {}
};
bool operator<(const Bridge& lb, const Bridge& rb) {
    return lb.v > rb.v || (lb.v == rb.v && lb.p > rb.p);
}
bool operator==(const Bridge& lb, const Bridge& rb) {
    return lb.v == rb.v && lb.p == rb.p;
}
bool operator<=(const Bridge& lb, const Bridge& rb) {
    return lb < rb || lb == rb;
}
bool operator>(const Bridge& lb, const Bridge& rb) {
    return lb.v < rb.v || (lb.v == rb.v && lb.p < rb.p);
}

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    int n, m;
    scanf("%d %d", &n, &m);
    List<Bridge> bs;
    List<Bridge> rs;
    AVL<int> ps;
    int p, v;
    for (int i = 0; i != n; ++i) {
        scanf("%d %d", &p, &v);
        bs.insertAsLast(Bridge(p, v));
    }
    for (int i = 0; i != m; ++i) {
        scanf("%d %d", &p, &v);
        rs.insertAsLast(Bridge(p, v));
    }
    bs.sort();
    rs.sort();
    long long sum = 0;
    for (auto p = bs.first(), q = rs.first(); p != bs.last()->succ; p = p->succ) {
        while (q != rs.last()->succ && q->data.v >= p->data.v) {
            ps.insert(q->data.p);
            q = q->succ;
        }
        BinNodePosi<int>& x = ps.search(p->data.p), xx;
        if (x)
            xx = x;
        else if (&x == &(ps._hot->lc))
            xx = ps._hot;
        else
            xx = ps._hot->succ();
        sum += (long long)(xx->data);
        ps.remove(xx->data);
    }
    printf("%lld", sum);
    return 0;
}
