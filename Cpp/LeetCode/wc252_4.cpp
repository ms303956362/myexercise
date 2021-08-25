#include "usual.h"

class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
        long long MOD = 1e9 + 7;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (nums[i - 1] == j) {
                    if (j > 0) {
                        dp[i][j] = (dp[i][j] + (dp[i - 1][j - 1] > 0 ? (dp[i - 1][j - 1]) : 0)) % MOD;
                        dp[i][j] = (dp[i][j] + (dp[i - 1][j] > 0 ? (dp[i - 1][j]) : 0)) % MOD;
                    } else {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j] + 1) % MOD;
                    }
                }
            }
        }
        return dp[n][2];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
