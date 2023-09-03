#include "usual.h"

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int l = 0, h = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; ++i) {
            h = max(h, nums[i] - nums[i - 1]);
        }
        vector<vector<int>> dp(n, vector<int>(2));
        auto check = [&](int m) {
            if (n > 1) {
                dp[1] = vector<int>(2);
            }
            if (n > 1 && nums[1] - nums[0] <= m) {
                dp[1][1] = 1;
            }
            for (int i = 2; i < n; ++i) {
                dp[i] = dp[i - 1];
                if (nums[i] - nums[i - 1] <= m) {
                    dp[i][1] = max(dp[i][1], max(dp[i - 2][1], dp[i - 2][0]) + 1);
                }
            }
            return max(dp[n - 1][0], dp[n - 1][1]) >= p;
        };
        int ans = 0;
        while (l <= h) {
            int m = (l + h) / 2;
            if (check(m)) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
