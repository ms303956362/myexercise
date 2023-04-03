#include "usual.h"

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        if (2 * k > sum) {
            return 0;
        }
        long long mod = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(k));
        dp[n][0] = 1;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1];
            for (int j = nums[i]; j < k; ++j) {
                dp[i][j] = (dp[i][j] + dp[i + 1][j - nums[i]]) % mod;
            }
        }
        long long ans = 1;
        for (int i = 0; i < n; ++i) {
            ans = (ans * 2) % mod;
        }
        for (int j = 0; j < k; ++j) {
            ans = ((ans - dp[0][j] * 2) % mod + mod) % mod;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
