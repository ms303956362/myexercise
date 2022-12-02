#include "usual.h"

class Solution {
public:
    int minRemainingSpace(vector<int>& N, int V) {
        int n = N.size();
        vector<vector<int>> dp(n + 1, vector<int>(V + 1));
        for (int j = 0; j <= V; ++j) {
            dp[n][j] = j;
        }
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1];
            for (int j = N[i]; j <= V; ++j) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j - N[i]]);
            }
        }
        return dp[0][V];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
