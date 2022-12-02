#include "usual.h"

int dp[1005][1005];

class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();
        vector<bool> is_prime(10);
        is_prime[2] = true;
        is_prime[3] = true;
        is_prime[5] = true;
        is_prime[7] = true;
        int mod = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        dp[n][0] = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (!is_prime[s[i] - '0']) {
                continue;
            }
            for (int j = i + minLength - 1; j < n; ++j) {
                if (is_prime[s[j] - '0']) {
                    continue;
                }
                for (int t = 1; t <= k; ++t) {
                    dp[i][t] = (dp[i][t] + dp[j + 1][t - 1]) % mod;
                }
            }
        }
        return dp[0][k];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
