#include "usual.h"

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<vector<vector<int>>> v(n);
        for (const auto& o : offers) {
            v[o[1]].push_back(o);
        }
        vector<int> dp(n);
        for (const auto& o : v[0]) {
            dp[0] = max(dp[0], o[2]);
        }
        int ans = dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1];
            for (const auto& o : v[i]) {
                if (o[0] > 0) {
                    dp[i] = max(dp[i], dp[o[0] - 1] + o[2]);
                } else {
                    dp[i] = max(dp[i], o[2]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
