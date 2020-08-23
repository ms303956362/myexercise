#include "usual.h"

class Solution {
    int dp[505][505];
    int sum[505];

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        sum[0] = 0;
        for (int i = 0; i != n; ++i) {
            sum[i + 1] = sum[i] + stoneValue[i];
        }
        for (int i = 0; i != 505; ++i)
            for (int j = 0; j != 505; ++j)
                dp[i][j] = 0;
        int res;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= n - i; ++j) {
                for (int k = j; k < j + i - 1; ++k) {
                    if (sum[k + 1] - sum[j] < sum[j + i] - sum[k + 1]) {
                        res = dp[j][k] + sum[k + 1] - sum[j];
                    } else if (sum[k + 1] - sum[j] > sum[j + i] - sum[k + 1]) {
                        res = dp[k + 1][j + i - 1] + sum[j + i] - sum[k + 1];
                    } else {
                        res = max(dp[j][k] + sum[k + 1] - sum[j], dp[k + 1][j + i - 1] + sum[j + i] - sum[k + 1]);
                    }
                    dp[j][j + i - 1] = max(dp[j][j + i - 1], res);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{6, 2, 3, 4, 5, 5};
    Solution().stoneGameV(a);
    return 0;
}
