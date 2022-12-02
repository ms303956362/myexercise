#include "usual.h"

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            long long lcm = nums[i];
            if (lcm == k) {
                ++ans;
            }
            for (int j = i + 1; j < n && lcm <= k; ++j) {
                long long g = __gcd((long long)nums[j], lcm);
                lcm = lcm / g * nums[j];
               if (lcm == k) {
                    ++ans;
               }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
