#include "usual.h"

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size(), MAX = pow(3, numSlots);
        vector<vector<int>> dp(n + 1, vector<int>(MAX));
        dp[n][0] = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int s = 0; s < MAX; ++s) {
                int pow = 1, tmp = s;
                for (int j = 0; j < numSlots && tmp > 0; ++j) {
                    if (tmp % 3 > 0) {
                        int s_next = s - pow;
                        dp[i][s] = max(dp[i][s], dp[i + 1][s_next] + (nums[i] & (j + 1)));
                    }
                    tmp /= 3;
                    pow *= 3;
                }
            }
        }
        int ans = 0;
        for (int s = 0; s < MAX; ++s) {
            int cnt = 0, tmp = s;
            for (int j = 0; j < numSlots && tmp > 0; ++j) {
                cnt += tmp % 3;
                tmp /= 3;
            }
            if (cnt == n) {
                ans = max(ans, dp[0][s]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{1, 2, 3, 4, 5, 6};
    int ns = 3;
    Solution().maximumANDSum(a, ns);
    return 0;
}
