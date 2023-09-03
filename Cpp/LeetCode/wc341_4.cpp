#include "usual.h"

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        function<bool(int, int, int, vector<int>&)> dfs = [&](int u, int f, int target, vector<int>& path) {
            path.push_back(u);
            if (u == target) {
                return true;
            }
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                if (dfs(v, u, target, path)) {
                    return true;
                }
            }
            path.pop_back();
            return false;
        };
        vector<int> cnt(n);
        for (const auto& t : trips) {
            vector<int> path;
            dfs(t[0], -1, t[1], path);
            for (const auto& u : path) {
                ++cnt[u];
            }
        }
        function<pair<int, int>(int, int)> dfs2 = [&](int u, int f) {
            int dp0 = price[u] * cnt[u], dp1 = price[u] * cnt[u] / 2;
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                auto [ret0, ret1] = dfs2(v, u);
                dp0 += min(ret0, ret1);
                dp1 += ret0;
            }
            return make_pair(dp0, dp1);
        };
        int ans = 0x3f3f3f3f;
        for (int r = 0; r < n; ++r) {
            auto [ret0, ret1] = dfs2(r, -1);
            ans = min({ans, ret0, ret1});
        }
        return ans;
    }
};