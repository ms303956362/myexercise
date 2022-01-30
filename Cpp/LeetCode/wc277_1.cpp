#include "usual.h"

class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        sort(nums.begin(), nums.end());
        while (i < n && nums[i] == nums[0])
            ++i;
        while (j >= 0 && nums[j] == nums[n - 1])
            --j;
        return max(0, j - i + 1);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
