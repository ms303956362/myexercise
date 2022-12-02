#include "usual.h"

class Solution {
public:
    int countHousePlacements(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(2));
        long long mod = 1e9 + 7;
        dp[n][0] = 1;
        for (int i = n - 1; i >= 0; --i) {
            dp[i][0] = (dp[i + 1][0] + dp[i + 1][1]) % mod;
            dp[i][1] = dp[i + 1][0] % mod;
        }
        return (dp[0][0] + dp[0][1]) * (dp[0][0] + dp[0][1]) % mod;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
