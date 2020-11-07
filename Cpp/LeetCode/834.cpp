#include "usual.h"

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        vector<int> dp(n, 0), sz(n, 1), ans(n, 0);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(0, -1, g, dp, sz);
        dfs1(0, -1, g, dp, sz,ans);
        return ans;
    }

    void dfs(int u, int p, vector<vector<int>>& g, vector<int>& dp, vector<int>& sz) {
        for (const auto& v : g[u]) {
            if (v != p) {
                dfs(v, u, g, dp, sz);
                dp[u] += dp[v] + sz[v];
                sz[u] += sz[v];
            }
        }
    }

    void dfs1(int u, int p, vector<vector<int>>& g, vector<int>& dp, vector<int>& sz, vector<int>& ans) {
        ans[u] = dp[u];
        for (const auto& v : g[u]) {
            if (v != p) {
                int dpu = dp[u], dpv = dp[v];
                int szu = sz[u], szv = sz[v];
                dp[u] -= dp[v] + sz[v];
                sz[u] -= sz[v];
                dp[v] += dp[u] + sz[u];
                sz[v] += sz[u];
                dfs1(v, u, g, dp, sz, ans);
                dp[u] = dpu, dp[v] = dpv;
                sz[u] = szu, sz[v] = szv;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int n = 6;
    vector<vector<int>> edges{{ 0, 1 }, { 0, 2 }, { 2, 3 }, { 2, 4 }, { 2, 5 }};
    Solution().sumOfDistancesInTree(n, edges);
    return 0;
}
