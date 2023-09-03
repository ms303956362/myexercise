#include "usual.h"

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = nums[0];
        for (int s = 1; s < (1 << n); ++s) {
            long long mul = 1;
            for (int i = 0; i < n; ++i) {
                if (s & (1 << i)) {
                    mul *= (long long)nums[i];
                }
            }
            ans = max(ans, mul);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
