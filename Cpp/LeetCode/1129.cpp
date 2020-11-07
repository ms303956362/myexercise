#include "usual.h"

class Solution {
    
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> ans(n, vector<int>(2, -1)); // 0: red, 1: blue;
        vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
        for (const auto& e : red_edges) {
            g[e[0]].push_back({e[1], 0});
        }
        for (const auto& e : blue_edges) {
            g[e[0]].push_back({e[1], 1});
        }
        queue<pair<int, int>> q;
        q.push({0, 3});
        ans[0][0] = 0;
        ans[0][1] = 0;
        int level = 0;
        while (!q.empty()) {
            int l = q.size();
            ++level;
            for (int i = 0; i != l; ++i) {
                auto [u, cu] = q.front();
                q.pop();
                for (const auto& [v, cv] : g[u]) {
                    if (ans[v][cv] < 0 && cv != cu) {
                        ans[v][cv] = level;
                        q.push({v, cv});
                    }
                }
            }
        }
        vector<int> ret(n, 0);
        for (int i = 0; i != n; ++i)
            ret[i] = min(ans[i][0], ans[i][1]);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    int n = 4;
    vector<vector<int>> r{{ 0, 1 }, { 0, 2 }, { 2, 3 }}, b{{ 1, 2 }};
    Solution().shortestAlternatingPaths(n, r, b);
    return 0;
}
