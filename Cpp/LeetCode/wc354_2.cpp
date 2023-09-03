#include "usual.h"

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, ans = 1;
        while (i < n) {
            while (j < n && nums[j] - nums[i] <= 2 * k) {
                ++j;
            }
            ans = max(ans, j - i);
            ++i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
