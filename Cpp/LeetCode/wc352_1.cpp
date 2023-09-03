#include "usual.h"

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        auto check = [&](int l, int r) {
            if (nums[l] % 2 != 0) {
                return false;
            }
            for (int i = l; i < r; ++i) {
                if (nums[i] % 2 == nums[i + 1] % 2) {
                    return false;
                }
                if (nums[i] > threshold) {
                    return false;
                }
            }
            return nums[r] <= threshold;
        };
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (check(i, j)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
