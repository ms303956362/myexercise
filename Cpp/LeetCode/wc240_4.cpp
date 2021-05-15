#include "usual.h"

class Solution {
    int ans;

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), m = edges.size();
        vector<vector<int>> g(n);
        vector<int> indegree(n), outdegree(n), vst(n);
        vector<vector<int>> dp(n, vector<int>(26));
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            ++indegree[e[1]];
            ++outdegree[e[0]];
        }
        ans = -1;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0 && !dfs(i, vst, dp, g, colors, outdegree))
                return -1;
            for (int j = 0; j < 26; ++j)
                ans = max(ans, dp[i][j]);
        }
        return ans;
    }

    bool dfs(int u, vector<int>& vst, vector<vector<int>>& dp, vector<vector<int>>& g, const string& colors, vector<int>& outdegree) {
        vst[u] = 1;
        cout << u << " ";
        if (outdegree[u] == 0) {
            dp[u][colors[u] - 'a'] = 1;
        } else {
            for (const auto& v : g[u]) {
                if (vst[v] == 1 || (!vst[v] && !dfs(v, vst, dp, g, colors, outdegree)))
                    return false;
                for (int j = 0; j < 26; ++j)
                    dp[u][j] = max(dp[u][j], dp[v][j] + ((colors[u] - 'a') == j));
            }
        }
        vst[u] = 2;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    string s("abaca");
    vector<vector<int>> v{ { 0, 1 }, { 0, 2 }, { 2, 3 }, { 3, 4 } };
    Solution().largestPathValue(s, v);
    return 0;
}
