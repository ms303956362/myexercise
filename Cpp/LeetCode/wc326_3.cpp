#include "usual.h"

class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, n + 1);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j <= i + 10 && j <= n; ++j) {
                long long num = stoll(s.substr(i, j - i));
                if (num > k) {
                    break;
                }
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[0] > n ? -1 : dp[0];
    }
};