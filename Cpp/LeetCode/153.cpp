#include "usual.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (nums[l] < nums[h]) {
                h = m - 1;
            } else {
                if (nums[m] < nums[h])
                    h = m - 1;
                else
                    l = m + 1;
            }
        }
        if (l >= n)
            return nums[h];
        else if (h < 0)
            return nums[l];
        return min(nums[l], nums[h]);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{4, 5, 1, 2, 3};
    Solution().findMin(v);
    return 0;
}
