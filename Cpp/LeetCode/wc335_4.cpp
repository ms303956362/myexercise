#include "usual.h"

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        long long mod = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1));
        dp[n][0] = 1;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1];
            int cnt = types[i][0], mk = types[i][1];
            for (int j = 0; j <= target; ++j) {
                for (int c = 1; c <= cnt && c * mk <= j; ++c) {
                    dp[i][j] = (dp[i][j] + dp[i + 1][j - c * mk]) % mod;
                }
            }
        }
        return dp[0][target];
    }
};

int main(int argc, char const *argv[])
{
    int t = 18;
    vector<vector<int>> v{{6,1},{3,2},{2,3}};
    Solution().waysToReachTarget(t, v);
    return 0;
}
