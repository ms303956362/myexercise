#include "usual.h"

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i) {
            queue<pair<int, int>> q;
            q.emplace(i, -1);
            vector<int> level(n, -1);
            level[i] = 0;
            int step = 0;
            while (!q.empty()) {
                int l = q.size();
                ++step;
                while (l--) {
                    auto [u, f] = q.front();
                    q.pop();
                    for (const auto& v : g[u]) {
                        if (level[v] >= 0) {
                            if (v != f && level[u] + level[v] >= 2) {
                                ans = min(ans, level[u] + level[v] + 1);
                            }
                        } else {
                            level[v] = step;
                            q.emplace(v, u);
                        }
                    }
                }
            }
        }
        return ans >= 0x3f3f3f3f ? -1 : ans;
    }
};

int main(int argc, char const *argv[])
{
    int n = 7;
    vector<vector<int>> e{{0,1},{1,2},{2,0},{3,4},{4,5},{5,6},{6,3}};
    Solution().findShortestCycle(n, e);
    return 0;
}
