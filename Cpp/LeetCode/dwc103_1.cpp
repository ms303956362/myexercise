#include "usual.h"

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < k; ++i) {
            ans += nums.back() + i;
        }
        return ans;
    }
};