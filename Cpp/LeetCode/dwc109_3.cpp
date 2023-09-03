#include "usual.h"

class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2));
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1];
            if (nums[i] % 2 == 0) {
                dp[i][0] = max(dp[i][0], max(dp[i + 1][0] + (long long)nums[i], dp[i + 1][1] + (long long)nums[i] - (long long)x));
            } else {
                dp[i][1] = max(dp[i][1], max(dp[i + 1][0] + (long long)nums[i] - (long long)x, dp[i + 1][1] + (long long)nums[i]));
            }
        }
        if (nums[0] % 2 == 0) {
            return max(dp[1][0] + (long long)nums[0], dp[1][1] + (long long)nums[0] - (long long)x);
        }
        return max(dp[1][0] + (long long)nums[0] - (long long)x, dp[1][1] + (long long)nums[0]);
    }
};
