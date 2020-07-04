#include "usual.h"

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        long long res = 0;
        int i, j;
        for (i = 0, j = n - 1; i < j; ) {
            if (nums[i] + nums[j] > target) {
                --j;
            } else {
                // res += (long long)pow(2, j - i) % MOD;
                res += Pow_mod(2, j - i, MOD);
                res %= MOD;
                ++i;
            }
        }
        if (j == i && nums[i] * 2 <= target)
            ++res;
        return res;
    }

    long long Pow_mod(long long a, long long b, long long m) {
        long long ans = 1;
        a = a % m;
        while (b > 0) 
        {
            if (b & 1) 
                ans = ans * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return ans;
    }
};