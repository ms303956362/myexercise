#include "usual.h"

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<long long> xl, xr;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                xl.push_back(nums[i]);
            } else {
                xr.push_back((long long)nums[i] + 2 * (long long)d);
            }
        }
        sort(xl.begin(), xl.end());
        sort(xr.begin(), xr.end());
        long long l = xl.size();
        long long ans = 0, mod = 1e9 + 7;
        vector<long long> pre_pos(l + 1), pre_neg(l + 1);
        for (int i = l - 1; i >= 0; --i) {
            pre_pos[i] = pre_pos[i + 1] + xl[i];
            pre_neg[i] = pre_neg[i + 1] - xl[i];
            ans = (ans + pre_pos[i + 1] - (l - i - 1) * xl[i]) % mod;
        }
        long long l2 = xr.size();
        vector<long long> pre_pos2(l2 + 1), pre_neg2(l2 + 1);
        for (int i = l2 - 1; i >= 0; --i) {
            pre_pos2[i] = pre_pos2[i + 1] + xr[i];
            pre_neg2[i] = pre_neg2[i + 1] - xr[i];
            ans = (ans + pre_pos2[i + 1] - (l2 - i - 1) * xr[i]) % mod;
        }
        for (const auto& x : xr) {
            int i = lower_bound(xl.begin(), xl.end(), x) - xl.begin();
            ans = ((ans + pre_pos[i] - pre_pos[l] - (l - i) * x + i * x + pre_neg[0] - pre_neg[i]) % mod + mod) % mod;
        }

        return (ans % mod + mod) % mod;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
