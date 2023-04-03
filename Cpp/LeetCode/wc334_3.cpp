#include "usual.h"

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, h = n / 2, ans = 0;
        auto check = [&](int m) {
            int i = 0, j = n - m;
            while (i < m) {
                if (2 * nums[i] > nums[j]) {
                    return false;
                }
                ++i;
                ++j;
            }
            return true;
        };
        while (l <= h) {
            int m = (l + h) / 2;
            if (check(m)) {
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return ans * 2;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
