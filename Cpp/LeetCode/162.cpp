#include "usual.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        else if (nums.size() == 2)
            return nums[0] < nums[1] ? 1 : 0;
        int l = 0, h = nums.size() - 1, m = 0, n = nums.size();
        while (l <= h) {
            m = (l + h) / 2;
            if (m == 0 || m == n - 1 || (nums[m - 1] < nums[m] && nums[m] > nums[m + 1]))
                return m;
            else if (nums[m] < nums[m + 1])
                l = m + 1;
            else
                h = m - 1;
        }
        return l;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{3,4,3,2,1};
    Solution().findPeakElement(v);
    return 0;
}
