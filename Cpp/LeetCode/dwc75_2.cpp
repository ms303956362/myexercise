#include "usual.h"

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int t = n - 1; t > 0; --t) {
            for (int i = 0; i < t; ++i) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
