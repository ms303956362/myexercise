#include "usual.h"

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g1(n, vector <int>()), g2(n, vector <int>()), g3(n, vector <int>());
        for (const auto& e : edges) {
            if (e[0] == 1 || e[0] == 3) {
                g1[e[1] - 1].push_back(e[2] - 1);
                g1[e[2] - 1].push_back(e[1] - 1);
            }
            if (e[0] == 2 || e[0] == 3) {
                g2[e[1] - 1].push_back(e[2] - 1);
                g2[e[2] - 1].push_back(e[1] - 1);
            }
            if (e[0] == 3) {
                g3[e[1] - 1].push_back(e[2] - 1);
                g3[e[2] - 1].push_back(e[1] - 1);
            }
        }
        vector<bool> vst1(n, false), vst2(n, false);
        if (dfs(0, g1, vst1) == n && dfs(0, g2, vst2) == n) {
            vector<bool> vst(n, false);
            int cnt_pub = 0;
            for (int i = 0; i != n; ++i) {
                if (!vst[i])
                    cnt_pub += dfs(i, g3, vst) - 1;
            }
            return edges.size() - (n - 1) * 2 + cnt_pub;
        }
        return -1;
    }

    int dfs(int u, vector<vector<int>>& g, vector<bool>& vst) {
        vst[u] = true;
        int cnt = 1;
        for (const auto& v : g[u]) {
            if (!vst[v])
                cnt += dfs(v, g, vst);
        }
        return cnt;
    }
};

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

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py)
            return;
        if (r[px] < r[py])  // 低树的作为高树的子树，高树高度不变
            p[px] = py;
        else {
            p[py] = px;
            if (px == py)   // 树高相等，默认px为py祖先，且需px高度加1
                r[px]++;
        }
    }
};

class Solution1 {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU uf(n), uf1(n);
        sort(edges.begin(), edges.end());
        int i = edges.size() - 1, cnt = 0, e1 = 0, e2 = 0;
        for (; i >= 0 && edges[i][0] == 3; --i) {
            int x = edges[i][1] - 1, y = edges[i][2] - 1;
            if (uf.find(x) == uf.find(y))
                ++cnt;
            else {
                uf.unite(x, y);
                uf1.unite(x, y);
                ++e1;
                ++e2;
            }
        }
        for (; i >= 0 && edges[i][0] == 2; --i) {
            int x = edges[i][1] - 1, y = edges[i][2] - 1;
            if (uf.find(x) == uf.find(y))
                ++cnt;
            else {
                uf.unite(x, y);
                ++e1;
            }
        }
        for (; i >= 0 && edges[i][0] == 1; --i) {
            int x = edges[i][1] - 1, y = edges[i][2] - 1;
            if (uf1.find(x) == uf1.find(y))
                ++cnt;
            else {
                uf1.unite(x, y);
                ++e2;
            }
        }
        if (e1 != n - 1 || e2 != n - 1)
            return -1;
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> e{{ 3, 1, 2 }, { 2, 2, 3 }, { 3, 1, 4 }, { 2, 3, 5 }, { 1, 2, 6 }, { 2, 4, 7 }, { 3, 3, 8 }, { 3, 2, 9 }, { 2, 1, 10 }, { 2, 1, 11 }, { 1, 11, 12 }, { 1, 10, 11 }, { 2, 5, 9 }, { 2, 7, 10 }, { 2, 4, 12 }, { 3, 9, 10 }, { 1, 6, 9 }, { 2, 10, 12 }, { 1, 2, 5 }, { 3, 5, 6 }, { 1, 7, 11 }, { 1, 8, 9 }, { 1, 1, 11 }, { 3, 4, 5 }, { 1, 5, 9 }, { 2, 4, 9 }, { 1, 8, 11 }, { 3, 6, 8 }, { 1, 8, 10 }, { 2, 2, 4 }, { 2, 3, 8 }, { 3, 2, 6 }, { 3, 10, 11 }, { 2, 3, 11 }, { 3, 5, 9 }, { 3, 3, 5 }, { 2, 6, 11 }, { 3, 2, 7 }, { 1, 5, 11 }, { 1, 1, 5 }, { 2, 9, 10 }, { 1, 6, 7 }, { 3, 2, 3 }, { 2, 8, 9 }, { 3, 2, 8 }};
    int n = 12;
    Solution().maxNumEdgesToRemove(n, e);
    return 0;
}
