#include "usual.h"

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> bobpath;
        function<bool(int, int)> dfs0 = [&](int u, int f) {
            bobpath.push_back(u);
            if (u == bob) {
                return true;
            }
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                if (dfs0(v, u)) {
                    return true;
                }
            }
            bobpath.pop_back();
            return false;
        };
        dfs0(0, -1);
        vector<int> bobtime(n, INT_MAX);
        int m = bobpath.size();
        for (int i = 0; i < m; ++i) {
            bobtime[bobpath.back()] = i;
            bobpath.pop_back();
        }
        int ans = INT_MIN;
        function<void(int, int, int, int)> dfs = [&](int u, int f, int t, int sum) {
            if (t < bobtime[u]) {
                sum += amount[u];
            } else if (t == bobtime[u]) {
                sum += amount[u] / 2;
            }
            if (g[u].size() == 1 && g[f][0] == f) {
                ans = max(ans, sum);
                return;
            }
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                dfs(v, u, t + 1, sum);
            }
        };
        dfs(0, -1, 0, 0);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> e{{0,1},{1,2},{1,3},{3,4}};
    int b = 3;
    vector<int> a{-2,4,2,-4,6};
    Solution().mostProfitablePath(e, b, a);
    return 0;
}
