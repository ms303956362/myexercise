#include "usual.h"

class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int ans = 0, last = 0x3fffffff;
        for (const auto& num : nums) {
            last &= num;
            if (last == 0) {
                ++ans;
                last = 0x3fffffff;
            }
        }
        return max(ans, 1);
    }
};