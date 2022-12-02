#include "usual.h"

class Solution {
public:
    int brilliantSurprise(vector<vector<int>>& present, int limit) {
        int n = present.size();
        vector<vector<int>> pre(n);
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            pre[i].push_back(0);
            int m = present[i].size();
            for (int j = 0; j < m; ++j) {
                pre[i].push_back(pre[i].back() + present[i][j]);
            }
        }
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(limit + 1));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= limit; ++j) {
                // dp[i][j] = dp[i + 1]
            }
        }
    }
};