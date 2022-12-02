#include "usual.h"

class Solution {
public:
    int minTransfers(vector<vector<int>>& distributions) {
        vector<int> a, d(12);
        for (const auto& dis : distributions) {
            d[dis[0]] -= dis[2];
            d[dis[1]] += dis[2];
        }
        for (int i = 0; i < 12; ++i) {
            if (d[i] != 0) {
                a.push_back(d[i]);
            }
        }
        if (a.empty()) {
            return 0;
        }
        int n = a.size();
        vector<int> dp(1 << n, -1);
        for (int s = 0; s < (1 << n); ++s) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (s & (1 << i)) {
                    sum += a[i];
                }
            }
            if (sum == 0) {
                dp[s] = 1;
            }
            for (int t = (s - 1) & s; t > 0 ; t = (t - 1) & s) {
                if (dp[t] > 0 && dp[s ^ t] > 0) {
                    dp[s] = max(dp[s], dp[t] + dp[s ^ t]);
                }
            }
        }
        return n - dp[(1 << n) - 1];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
