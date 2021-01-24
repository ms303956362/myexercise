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
            if (r[px] == r[py])   // 树高相等，默认px为py祖先，且需px高度加1
                r[px]++;
        }
        return true;
    }
};


class BIT {
    int n;
    vector<int> tree;
public:
    BIT(int _n) : n(_n + 1), tree(_n + 1, 0) {}
    BIT(const vector<int>& a) : n(a.size() + 1), tree(a.size() + 1, 0) {
        for (int i = 1; i < n; ++i) {
            update(i - 1, a[i - 1]);
        }
    }

    inline int lowBit(int i) { return i & (-i); }

    void update(int i, int delta) {
        ++i;
        while (i < n) {
            tree[i] += delta;
            i += lowBit(i);
        }
    }

    int query(int i) {
        ++i;
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= lowBit(i);
        }
        return sum;
    }

};

int prim(vector<vector<pair<int, int>>>& edges) {
    int n = edges.size();
    priority_queue<pair<int, int>> q;
    vector<bool> vst(n, false);
    vst[0] = true;
    for (const auto& e : edges[0]) {
        q.push(e);
    }
    int ans = 0;
    for (int i = 0; i != n - 1; ++i) {
        while (vst[q.top().second])
            q.pop();
        int d = q.top().first, j = q.top().second;
        vst[j] = true;
        ans -= d;
        // cout << "j=" << j << " d=" << -d << " ans=" << ans << endl;
        for (const auto& e : edges[j]) {
            if (!vst[e.second])
                q.push(e);
        }
    }
    return ans;
}
