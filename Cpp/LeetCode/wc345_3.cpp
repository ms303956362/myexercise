#include "usual.h"

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n + 1));
        for (int j = n - 1; j >= 0; --j) {
            for (int i = 0; i < m; ++i) {
                dp[i][j] = 1;
                for (int k = max(i - 1, 0); k <= min(i + 1, m - 1); ++k) {
                    if (j == n - 1 || grid[k][j + 1] > grid[i][j]) {
                        dp[i][j] = max(dp[i][j], dp[k][j + 1] + 1);
                    }
                }
            }
        }
        int ans = 1;
        for (int i = 0; i < m; ++i) {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
