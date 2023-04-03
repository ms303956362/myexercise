#include "usual.h"

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ans = 0;
        long long n = nums.size();
        for (int k = 0; k < 31; ++k) {
            long long c0 = 0, c1 = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] & (1 << k)) {
                    ++c1;
                } else {
                    ++c0;
                }
            }
            if (((n * n - c0 * c0) * c1) % 2 == 1) {
                ans |= (1 << k);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
