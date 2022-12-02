#include "usual.h"

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;
        int i = 0, j = 0, n = nums.size();
        int sum = 0;
        while (i < n) {
            while (j < n && (sum & nums[j]) == 0) {
                sum |= nums[j];
                ++j;
            }
            ans = max(ans, j - i);
            sum &= ~nums[i];
            ++i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
