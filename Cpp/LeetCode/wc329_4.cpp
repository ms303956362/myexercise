#include "usual.h"

class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n + 1, 0x3f3f3f3f3f3f3f3f);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            long long sum = 0;
            vector<long long> cnt(1005);
            for (int j = i; j < n; ++j) {
                ++cnt[nums[j]];
                if (cnt[nums[j]] == 2) {
                    sum += 2;
                } else if (cnt[nums[j]] > 2) {
                    ++sum;
                }
                dp[i] = min(dp[i], (long long)k + sum + dp[j + 1]);
            }
        }
        return dp[0];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
