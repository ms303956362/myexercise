#include "usual.h"

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1)), pre(n, vector<int>(2005));
        for (int i = n - 1; i >= 0; --i) {
            int m = piles[i].size();
            for (int t = 1; t <= m; ++t) {
                pre[i][t] = pre[i][t - 1] + piles[i][t - 1];
            }
            dp[i] = dp[i + 1];
            for (int j = 0; j <= k; ++j) {
                for (int t = 1; t <= min(j, m); ++t) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - t] + pre[i][t]);
                }
            }
        }
        return dp[0][k];
    }
};