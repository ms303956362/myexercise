#include "Vector.h"

struct Station {
    int x;
    int y;
    int temp;
    Station(int xx=0, int yy=0, int t=0) : x(xx), y(yy), temp(t) {}
};

struct Temp {
    int y;
    int temp;
    Temp(int yy=0, int t=0) : y(yy), temp(t) {}
};
bool operator<(const Temp& lt, const Temp& rt) { return lt.y < rt.y; }
bool operator<=(const Temp& lt, const Temp& rt) { return lt.y <= rt.y; }
bool operator==(const Temp& lt, const Temp& rt) { return lt.y == rt.y; }
bool operator>=(const Temp& lt, const Temp& rt) { return lt.y >= rt.y; }
bool operator>(const Temp& lt, const Temp& rt) { return lt.y > rt.y; }

struct RNode {
    int x;
    Vector<Temp> v;
    RNode *lc;
    RNode *rc;
    RNode(int xx) : x(xx), v(Vector<Temp>()), lc(nullptr), rc(nullptr){}
    RNode(int xx, int y, int t) : x(xx), v(1, Temp(y, t)), lc(nullptr), rc(nullptr) {}
};

void findMedian(Station* s, int n) {
    for (int lo = 0, hi = n - 1; lo < hi;) {
        int i = lo, j = hi;
        int pivot = s[lo].x;
        while (i < j) {
            while (i < j && pivot <= s[j].x)
                --j;
            s[i] = s[j];
            while (i < j && s[i].x <= pivot)
                ++i;
            s[j] = s[i];
        }
        if ((n - 1) / 2 <= i)
            hi = i - 1;
        if (i <= (n - 1) / 2)
            lo = i + 1;
    }
}

struct RangeTree {
    RNode *root;
    RangeTree(Station* s, int n) { root = build(s, n); }
    RNode* build(Station* s, int n) {
        if (n == 1)
            return new RNode(s->x, s->y, s->temp);
        // 按x取中位数，分组
        findMedian(s, n);
        RNode *x = new RNode(s[(n - 1) / 2].x);
        x->lc = build(s, (n + 1) / 2);
        x->rc = build(s + (n + 1) / 2, n - (n + 1) / 2);
        // 按y归并
        int lo = 0, mi = x->lc->v.size(), hi = mi + x->rc->v.size();
        for (int i = 0; i != mi; ++i) {
            x->v.insert(x->lc->v[i]);
        }
        for (int i = 0; i != hi - mi; ++i) {
            x->v.insert(x->rc->v[i]);
        }
        merge(x->v._elem, lo, mi, hi);
        return x;
    }

    int search(int x1, int y1, int x2, int y2) {
        return search(root, x1, y1, x2, y2);
    }

    int search(RNode* r, int x1, int y1, int x2, int y2) {
        long long sum = 0;
        int cnt = 0;
        // 找lca
        while (r) {
            if (x2 < r->x) // x2必须严格小于r->x，x2才全都在左子树
                r = r->lc;
            else if (r->x < x1)
                r = r->rc;
            else
                break;
        }
        if (!r)
            return 0;
        // 分头查找
        RNode* lt = r->lc ? r->lc : r, *rt = r->rc; // r为叶节点只需遍历一次r->v
        while (lt) {
            if (x1 <= lt->x) {  // x1在lt左子树，则右子树全在[x1, x2]内，查找y，深入左子树
                Vector<Temp> &v = lt->rc ? lt->rc->v : lt->v; // 只可能两个孩子或叶节点
                int last = v.search(y2);
                while (0 <= last && y1 <= v[last].y) {
                    sum += v[last].temp;
                    --last;
                    ++cnt;
                }
                lt = lt->lc;
            } else {  // lt->x < x1，左子树全不在[x1, x2]内，深入右子树
                lt = lt->rc;
            }
        }
        while (rt) {
            if (rt->x <= x2) {  // x2可能在rt右子树，左子树全在[x1, x2]内
                Vector<Temp> &v = rt->lc ? rt->lc->v : rt->v;
                int last = v.search(y2);
                while (0 <= last && y1 <= v[last].y) {
                    sum += v[last].temp;
                    --last;
                    ++cnt;
                }
                rt = rt->rc;
            } else {    // x2 < rt->x，左子树不全在[x1, x2]内，深入左子树查找
                rt = rt->lc;
            }
        }
        return cnt == 0 ? 0 : sum / cnt;
    }
};

