#include "usual.h"

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long ans = (long long)(1 + n) * (long long)n / 2;
        if (target > 2 * n - 1) {
            return ans;
        }
        if (target <= n + 1) {
            long long i = 1, j = target - 1, extra = n + 1;
            while (j > i) {
                ans -= j;
                ans += extra;
                ++extra;
                --j;
                ++i;
            }
        } else {
            long long i = target - n, j = n, extra = target;
            while (j > i) {
                ans -= j;
                ans += extra;
                ++extra;
                --j;
                ++i;
            }
        }
        return ans;
    }
};
