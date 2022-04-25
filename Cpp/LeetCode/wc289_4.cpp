#include "usual.h"

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; ++i) {
            g[parent[i]].push_back(i);
        }
        int ans = 0;
        vector<int> dp(n);
        function<void(int)> dfs = [&](int u)
        {
            int max_len = 0, second_max_len = 0;
            for (const auto& v : g[u]) {
                dfs(v);
                if (s[u] == s[v]) {
                    continue;
                }
                if (dp[v] > max_len) {
                    second_max_len = max_len;
                    max_len = dp[v];
                } else if (dp[v] > second_max_len) {
                    second_max_len = dp[v];
                }
            }
            dp[u] = max_len + 1;
            ans = max(ans, max_len + second_max_len + 1);
        };
        dfs(0);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
