#include "usual.h"

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        vector<vector<long long>> dp(n + 1, vector<long long>(n - k + 1));
        long long MOD = 1e9 + 7;
        for (int i = 0; i < n + 1; ++i)
            dp[i][0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= min(i, n - k); ++j) {
                dp[i][j] = (dp[i - 1][j] + (dp[i - 1][j - 1] * i) % MOD) % MOD;
            }
        }
        return dp[n - 1][n - k];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
