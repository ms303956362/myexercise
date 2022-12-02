#include "usual.h"

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        long long m = grid.size(), n = grid[0].size(), mod = 1e9 + 7;
        vector<vector<vector<long long>>> dp(m + 1, vector<vector<long long>>(n + 1, vector<long long>(k)));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1) {
                    dp[i][j][grid[i][j] % k] = 1;
                    continue;
                }
                for (int s = 0; s < k; ++s) {
                    long long t = ((s - grid[i][j] % k) % k + k) % k;
                    dp[i][j][s] = (dp[i + 1][j][t] + dp[i][j + 1][t]) % mod;
                }
            }
        }
        return dp[0][0][0];
    }
};
