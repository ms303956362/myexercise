#include "usual.h"

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0x3f3f3f3f;
        for (int i = 1; i < n; ++i) {
            ans = min(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
