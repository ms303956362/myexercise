#include "usual.h"

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int ans = 0;
        function<long long(int, int)> dfs = [&](int u, int f) {
            long long sum = values[u];
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                sum += dfs(v, u);
            }
            if (sum % k == 0) {
                ++ans;
            }
            return sum % k == 0 ? 0 : sum;
        };
        dfs(0, -1);
        return ans;
    }
};