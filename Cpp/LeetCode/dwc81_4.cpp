#include "usual.h"

class Solution {
public:
    int distinctSequences(int n) {
        if (n == 1) {
            return 6;
        }
        if (n == 2) {
            return 22;
        }
        long long mod = 1e9 + 7;
        vector<vector<long long>> dp(n, vector<long long>(36));
        for (int i = 0; i < 36; ++i) {
            int a1 = (i / 6) + 1, a2 = (i % 6) + 1;
            if (__gcd(a1, a2) != 1 || a1 == a2) {
                continue;
            }
            dp[n - 2][i] = 1;
            for (int j = 1; j <= 6; ++j) {
                if (j != a1 && j != a2 && __gcd(j, a2) == 1) {
                    ++dp[n - 3][i];
                }
            }
        }

        for (int i = n - 4; i >= 0; --i) {
            for (int j = 0; j < 36; ++j) {
                int a1 = (j / 6) + 1, a2 = (j % 6) + 1;
                if (__gcd(a1, a2) != 1 || a1 == a2) {
                    continue;
                }
                for (int k = 0; k < 36; ++k) {
                    int b1 = (k / 6) + 1, b2 = (k % 6) + 1;
                    if (__gcd(b1, b2) != 1 || __gcd(a2, b1) != 1 || a1 == b1 || a2 == b1 || a2 == b2 || b1 == b2) {
                        continue;
                    }
                    dp[i][j] = (dp[i][j] + dp[i + 2][k]) % mod;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < 36; ++i) {
            ans = (ans + dp[0][i]) % mod;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n = 4;
    Solution().distinctSequences(4);
    return 0;
}
