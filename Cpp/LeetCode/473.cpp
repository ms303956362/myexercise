#include "usual.h"

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum = 0;
        for (const auto& n : nums)
            sum += n;
        int n = nums.size();
        if (n < 4 || sum < 4 || sum % 4 != 0)
            return false;
        vector<bool> vst(n, false);
        for (int i = 0; i != 3; ++i)
            if (!backtrack(0, n, 0, sum / 4, vst, nums))
                return false;
        return true;
    }

    bool backtrack(int i, int n, int sum, int target, vector<bool>& vst, vector<int>& nums) {
        if (sum == target)
            return true;
        if (i == n || sum > target)
            return false;
        if (!vst[i]) {
            vst[i] = true;
            if (backtrack(i + 1, n, sum + nums[i], target, vst, nums))
                return true;
            vst[i] = false;
        }
        return backtrack(i + 1, n, sum, target, vst, nums);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    Solution().makesquare(nums);
    return 0;
}
