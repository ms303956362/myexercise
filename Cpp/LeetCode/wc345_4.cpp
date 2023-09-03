#include "usual.h"

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> cnt_edges(n), p(n), sz(n, 1);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        function<int(int)> find = [&](int u) {
            return p[u] == u ? u : (p[u] = find(p[u]));
        };
        auto merge = [&](int u, int v) {
            int pu = find(u), pv = find(v);
            if (pu == pv) {
                return;
            }
            p[pu] = pv;
            sz[pv] += sz[pu];
        };
        for (const auto& e : edges) {
            merge(e[0], e[1]);
        }
        for (const auto& e : edges) {
            ++cnt_edges[find(e[0])];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i == find(i) && cnt_edges[i] == (sz[i] * (sz[i] - 1) / 2)) {
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
