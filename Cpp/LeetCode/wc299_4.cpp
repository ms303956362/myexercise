#include "usual.h"

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<vector<bool>> fathers(n, vector<bool>(n));
        vector<int> path, val(n);
        function<void(int)> dfs = [&](int u) {
            for (const auto& v : path) {
                fathers[u][v] = true;;
            }
            path.push_back(u);
            val[u] = nums[u];
            for (const auto& v : g[u]) {
                if (!fathers[u][v]) {
                    dfs(v);
                    val[u] ^= val[v];
                }
            }
            path.pop_back();
        };
        dfs(0);
        int ans = INT_MAX;
        for (int u = 1; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                int s1 = 0, s2 = 0, s3 = 0;
                if (fathers[u][v]) {
                    s1 = val[0] ^ val[v];
                    s2 = val[v] ^ val[u];
                    s3 = val[u];
                } else if (fathers[v][u]) {
                    s1 = val[0] ^ val[u];
                    s2 = val[u] ^ val[v];
                    s3 = val[v];
                } else {
                    s1 = val[0] ^ val[u] ^ val[v];
                    s2 = val[u];
                    s3 = val[v];
                }
                ans = min(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1,5,5,4,11};
    vector<vector<int>> edges{{0,1},{1,2},{1,3},{3,4}};
    Solution().minimumScore(nums, edges);
    return 0;
}
