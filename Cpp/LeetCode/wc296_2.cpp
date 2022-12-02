#include "usual.h"

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        int i = 0;
        sort(nums.begin(), nums.end());
        while (i < n) {
            int j = i + 1;
            while (j < n && nums[j] - nums[i] <= k) {
                ++j;
            }
            ++ans;
            i = j;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
