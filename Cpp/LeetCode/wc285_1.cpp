#include "usual.h"

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            int j = i - 1, k = i + 1;
            while (j >= 0 && nums[j] == nums[i]) {
                --j;
            }
            if (j < 0) {
                continue;
            }
            if (nums[j] < nums[i] && nums[i] > nums[k]) {
                ++ans;
            } else if (nums[j] > nums[i] && nums[i] < nums[k]) {
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
