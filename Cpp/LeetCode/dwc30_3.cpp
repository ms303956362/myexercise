#include "usual.h"

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4)
            return 0;
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for (int i = 0; i <= 3; ++i) {
            int j = n - 4 + i;
            res = min(res, nums[j] - nums[i]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
