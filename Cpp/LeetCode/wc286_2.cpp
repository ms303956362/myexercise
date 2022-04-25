#include "usual.h"
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int i = 0, n = nums.size(), ans = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && nums[j] == nums[i]) {
                ++j;
            }
            if (j == n) {
                ans += j - i;
            } else {
                ans += j - i - 1;
            }
            i = j + 1;
        }
        return ans;
    }
};