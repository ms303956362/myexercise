#include "usual.h"

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size(), idx = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == k) {
                idx = i;
                break;
            }
        }
        map<long long, long long> dp0, dp1;
        if (n % 2 == 1) {
            dp1[0] = 1;
        } else {
            dp0[0] = 1;
        }
        long long c1 = 0, c2 = 0, ans = 0;
        for (int i = n - 1; i > idx; --i) {
            if (nums[i] > k) {
                ++c1;
            } else {
                ++c2;
            }
            if (i % 2 == 1) {
                ++dp1[c1 - c2];
            } else {
                ++dp0[c1 - c2];
            }
        }
        for (int i = idx; i >= 0; --i) {
            if (nums[i] > k) {
                ++c1;
            } else {
                ++c2;
            }
            if (i % 2 == 1) {
                ans += dp1[c1 - c2] + dp0[c1 - c2 + 1];
            } else {
                ans += dp0[c1 - c2] + dp1[c1 - c2 + 1];
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
