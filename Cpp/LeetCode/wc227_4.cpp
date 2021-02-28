#include "usual.h"

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size(), nl = n / 2, nr = n - n / 2;
        vector<int> lsum(1 << nl), rsum(1 << nr);
        enumNums(nums, lsum, 0, nl);
        enumNums(nums, rsum, nl, nr);
        sort(lsum.begin(), lsum.end());
        sort(rsum.begin(), rsum.end());
        int ans = INT_MAX;
        for (int i = 0, j = (1 << nr) - 1; i < (1 << nl) && j >= 0; ) {
            if (lsum[i] + rsum[j] < goal) {
                ans = min(ans, goal - lsum[i] - rsum[j]);
                ++i;
            } else if (lsum[i] + rsum[j] > goal) {
                ans = min(ans, lsum[i] + rsum[j] - goal);
                --j;
            } else {
                ans = 0;
                break;
            }
        }
        return ans;
    }

    void enumNums(vector<int>& nums, vector<int>& dp, int beg, int n) {
        for (int i = 1; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    dp[i] = dp[i - (1 << j)] + nums[beg + j];
                    break;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{5, -7, 3, 5};
    int goal = 6;
    Solution().minAbsDifference(nums, goal);
    return 0;
}
