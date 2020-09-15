#include "usual.h"

class DSU {
    int n;
    vector<int> p;  // 祖先
    vector<int> r;  // 树高 
public:
    DSU(int _n) : n(_n), p(_n), r(_n, 0) {
        for (int i = 0; i != n; ++i) {
            p[i] = i;
        }
    }

    int find(int x) {
        if (p[x] == x)
            return x;
        return p[x] = find(p[x]); // x的祖先直接设为根节点，路径压缩
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py)
            return false;
        if (r[px] < r[py])  // 低树的作为高树的子树，高树高度不变
            p[px] = py;
        else {
            p[py] = px;
            if (px == py)   // 树高相等，默认px为py祖先，且需px高度加1
                r[px]++;
        }
        return true;
    }
};
