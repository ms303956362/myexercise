#include "usual.h"

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return false;
        }
        sort(nums.begin(), nums.end());
        --n;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return false;
            }
        }
        if (nums[n] != n) {
            return false;
        }
        return true;
    }
};