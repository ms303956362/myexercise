#include "usual.h"

class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n, vector<int>());
        vector<int> ans(n, -1);
        vector<vector<pair<int, int>>> level(51, vector<pair<int, int>>());
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(0, -1, 0, nums, g, ans, level);
        return ans;
    }

    void dfs(int u, int p, int l, vector<int>& nums, vector<vector<int>>& g, vector<int>& ans, vector<vector<pair<int, int>>>& level) {
        int max_level = -1, max_p = -1;
        for (int i = 1; i <= 50; ++i) {
            if (__gcd(nums[u], i) == 1 && level[i].size() > 0 && level[i].back().second > max_level) {
                    max_p = level[i].back().first;
                    max_level = level[i].back().second;
            }
        }
        ans[u] = max_p;
        level[nums[u]].emplace_back(u, l);
        for (const auto& v : g[u]) {
            if (v != p)
                dfs(v, u, l + 1, nums, g, ans, level);
        }
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
