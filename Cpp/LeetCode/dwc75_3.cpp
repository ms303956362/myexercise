#include "usual.h"

class Solution {
    using ll = long long;

public:
    long long numberOfWays(string s) {
        int n = s.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(6));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][0] = dp[i + 1][0] + (s[i] == '0');
            dp[i][1] = dp[i + 1][1] + (s[i] == '1');
            dp[i][2] = dp[i + 1][2];
            if (s[i] == '0') {
                dp[i][2] += dp[i + 1][1];
            }
            dp[i][3] = dp[i + 1][3];
            if (s[i] == '1') {
                dp[i][3] += dp[i + 1][0];
            }
            dp[i][4] = dp[i + 1][4];
            if (s[i] == '0') {
                dp[i][4] += dp[i + 1][3];
            }
            dp[i][5] = dp[i + 1][5];
            if (s[i] == '1') {
                dp[i][5] += dp[i + 1][2];
            }
        }
        return dp[0][4] + dp[0][5];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
