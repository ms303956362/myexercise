#include "usual.h"

// int dp[305][305];
int Pow[305];

class Solution {
public:
    int numberOfWays(int n, int x) {
        int m = 0;
        for (int i = 1; i <= n; ++i) {
            int p = 1, j = 0;
            while (j < x && p <= n) {
                p *= i;
                ++j;
            }
            if (j == x && p <= n) {
                Pow[m++] = p;
            }
        }
        int mod = 1e9 + 7;
        // memset(dp, -1, 305 * 305 * sizeof(int));
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        function<void(int, int)> dfs = [&](int i, int j) {
            // if (dp[i][j] != -1) {
            //     return;
            // }
            // dp[i][j] = 0;
            // if (Pow[j] > i) {
            //     return;
            // } else if (Pow[j] == i) {
            //     dp[i][j] = 1;
            //     return;
            // }
            // for (int k = j - 1; k >= 0; --k) {
            //     dfs(i - Pow[j], k);
            //     dp[i][j] = (dp[i][j] + dp[i - Pow[j]][k]) % mod;
            // }
            if (dp[i][j] != -1) {
                return;
            }
            dp[i][j] = 0;
            if (j == m) {
                if (i == 0) {
                    dp[i][j] = 1;
                }
                return;
            }
            dfs(i, j + 1);
            dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
            if (i >= Pow[j]) {
                dfs(i - Pow[j], j + 1);
                dp[i][j] = (dp[i][j] + dp[i - Pow[j]][j + 1]) % mod;
            }
        };
        // int ans = 0;
        // for (int j = m - 1; j >= 0; --j) {
        //     dfs(n, j);
        //     ans = (ans + dp[n][j]) % mod;
        // }
        // return ans;
        dfs(n, 0);
        return dp[n][0];
    }
};