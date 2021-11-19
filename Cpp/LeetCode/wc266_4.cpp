#include "usual.h"

class Solution {
    int ans;

public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<pair<int, int>>> g(n);
        for (const auto& e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);
        }
        vector<int> vst(n);
        ans = 0;
        dfs(0, 0, ans, maxTime, vst, values, g);
        return ans;
    }

    void dfs(int u, int t, int val, int maxt, vector<int>& vst, vector<int>& values, vector<vector<pair<int, int>>>& g) {
        if (t > maxt)
            return;
        if (vst[u] == 0)
            val += values[u];
        if (u == 0)
            ans = max(ans, val);
        ++vst[u];
        for (const auto& [v, te] : g[u]) {
            dfs(v, t + te, ans, maxt, vst, values, g);
        }
        --vst[u];
        if (vst[u] == 0)
            val -= values[u];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{0, 32, 10, 43};
    vector<vector<int>> edges = {{0, 1, 10},
                                  {1, 2, 15},
                                  {0, 3, 10}};
    int maxTime = 49;
    Solution().maximalPathQuality(v, edges, maxTime);
    return 0;
}
