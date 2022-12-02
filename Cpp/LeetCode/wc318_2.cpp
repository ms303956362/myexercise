#include "usual.h"

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            pre[i] = pre[i + 1] + nums[i];
        }
        unordered_map<int, int> cnt;
        int i = 0, j = 0;
        long long ans = 0;
        while (i < n) {
            ++cnt[nums[i]];
            while (j < i && cnt[nums[i]] > 1) {
                --cnt[nums[j]];
                ++j;
            }
            while (i - j >= k) {
                --cnt[nums[j]];
                ++j;
            }
            if (i - j == k - 1) {
                ans = max(ans, pre[j] - pre[i + 1]);
            }
            ++i;
        }
        return ans;
    }
};