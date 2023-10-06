#include "usual.h"

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size(), i = 0, j = (n + 1) / 2, ans = n % 2;
        while (j < n) {
            if (nums[i] == nums[j]) {
                ans += 2;
            }
            ++i;
            ++j;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
