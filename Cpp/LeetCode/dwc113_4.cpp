#include "usual.h"

class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> g(n);
        for (const auto& e : edges) {
            g[e[0]].emplace_back(e[1], 1);
            g[e[1]].emplace_back(e[0], 0);
        }
        vector<int> dp1(n);
        function<void(int, int)> dfs1 = [&](int u, int f) {
            for (const auto& [v, dir] : g[u]) {
                if (v == f) {
                    continue;
                }
                if (!dir) {
                    ++dp1[u];
                }
                dfs1(v, u);
                dp1[u] += dp1[v];
            }
        };
        dfs1(0, -1);
        vector<int> ans(n);
        ans[0] = dp1[0];
        function<void(int, int)> dfs2 = [&](int u, int f) {
            for (const auto& [v, dir] : g[u]) {
                if (v == f) {
                    continue;
                }
                if (dir == 0) {
                    ans[v] = ans[u] - 1;
                } else {
                    ans[v] = ans[u] + 1;
                }
                dfs2(v, u);
            }
        };
        dfs2(0, -1);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n = 4;
    vector<vector<int>> edges{{2,0},{2,1},{1,3}};
    Solution().minEdgeReversals(n, edges);
    return 0;
}
