#include "usual.h"

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n);
        for (const auto& e : roads) {
            g[e[0] - 1].emplace_back(e[1] - 1, e[2]);
            g[e[1] - 1].emplace_back(e[0] - 1, e[2]);
        }
        int ans = INT_MAX;
        vector<bool> vst(n);
        function<void(int)> dfs = [&](int u) {
            vst[u] = true;
            for (const auto& [v, c] : g[u]) {
                ans = min(ans, c);
                if (!vst[v]) {
                    dfs(v);
                }
            }
        };
        dfs(0);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
