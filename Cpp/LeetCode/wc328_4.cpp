#include "usual.h"

using ll = long long;

class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(2));
        vector<int> p(n);
        function<void(int, int)> dfs = [&](int u, int  f) {
            p[u] = f;
            vector<pair<int, int>> scores;
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                dfs(v, u);
                scores.emplace_back(dp[v][0].first + price[u], v);
            }
            while (scores.size() < 2) {
                scores.emplace_back(price[u], -1);
            }
            sort(scores.rbegin(), scores.rend());
            dp[u][0] = scores[0];
            dp[u][1] = scores[1];
        };
        dfs(0, -1);
        ll ans = 0;
        // for (int u = 0; u < n; ++u) {
        //     ans = max(ans, dp[u][0].first - price[u]);
        //     if (p[u] != -1) {
        //         if (dp[p[u]][0].second != u) {
        //             ans = max(ans, dp[p[u]][0].first);
        //         } else if (dp[p[u]][1].second != u) {
        //             ans = max(ans, dp[p[u]][1].first);
        //         }
        //     }
        // }
        vector<vector<pair<ll, ll>>> dp2(n, vector<pair<ll, ll>>(2));
        function<void(int, int)> dfs2 = [&](int u, int f) {
            dp2[u] = dp[u];
            if (f != -1) {
                if (dp2[f][0].second != u) {
                    dp2[u].emplace_back(dp2[f][0].first + price[u], f);
                } else if (dp2[f][1].second != u) {
                    dp2[u].emplace_back(dp2[f][1].first + price[u], f);
                }
            }
            sort(dp2[u].rbegin(), dp2[u].rend());
            while (dp2[u].size() > 2) {
                dp2[u].pop_back();
            }
            ans = max(ans, dp2[u][0].first - price[u]);
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
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
    int n = 8;
    vector<vector<int>> e{{1,7},{2,3},{4,0},{5,7},{6,3},{3,0},{0,7}};
    vector<int> p{4,5,6,2,2,7,7,8};
    cout << Solution().maxOutput(n, e, p) << endl;
    return 0;
}
