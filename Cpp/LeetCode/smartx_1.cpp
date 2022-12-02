#include "usual.h"


int solve(vector<vector<int>> costs) {
    int n = costs.size();
    vector<vector<int>> dp(n + 1, vector<int>(3, 0x3f3f3f3f));
    dp[n][0] = dp[n][1] = dp[n][2] = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (k == j) {
                    continue;
                }
                dp[i][j] = min(dp[i][j], costs[i][j] + dp[i + 1][k]);
            }
        }
    }
    return min({dp[0][0], dp[0][1], dp[0][2]});
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> costs1{{13,2,11},{11,14,5},{16,3,10}};
    cout << solve(costs1) << endl;
    vector<vector<int>> costs2{{1,2,3},{1,4,6}};
    cout << solve(costs2) << endl;
    return 0;
}
