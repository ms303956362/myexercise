#include "usual.h"

class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0, MOD = 1e9 + 7;
        int prev_num = -1, prev_i = 0, curr_ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != prev_num) {
                prev_i = i;
                prev_num = nums[i];
                int prev_j = prev_i;
                int k = 2;
                curr_ans = 0;
                for (int k = 2; (k - 1) * nums[i] <= nums[n - 1]; ) {
                    int j = lower_bound(nums.begin(), nums.end(), nums[i] * k) - nums.begin();
                    curr_ans = (curr_ans + (k - 1) * (j - prev_j) % MOD) % MOD;
                    prev_j = j;
                    if (j < n)
                        k = nums[j] / nums[i] + 1;
                    else
                        break;
                }
            }
            ans = (ans + curr_ans) % MOD;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{2, 5, 9};
    Solution().sumOfFlooredPairs(v);
    return 0;
}
