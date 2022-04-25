#include "usual.h"

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1 && k % 2 == 1) {
            return -1;
        }
        if (k > n) {
            return *max_element(nums.begin(), nums.end());
        }
        if (k == 0) {
            return nums[0];
        }
        int max_num = INT_MIN;
        for (int i = 0; i <= k - 2; ++i) {
            max_num = max(max_num, nums[i]);
        }
        if (k == n) {
            return max_num;
        }
        return max(max_num, nums[k]);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
