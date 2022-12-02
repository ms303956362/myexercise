#include "usual.h"

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high + 5);
        dp[0] = 1;
        long long mod = 1e9 + 7;
        for (int i = 0; i <= high; ++i) {
            if (i - zero >= 0) {
                dp[i] = (dp[i] + dp[i - zero]) % mod;
            }
            if (i - one >= 0) {
                dp[i] = (dp[i] + dp[i - one]) % mod;
            }
        }
        long long ans = 0;
        for (int i = low; i <= high; ++i) {
            ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};