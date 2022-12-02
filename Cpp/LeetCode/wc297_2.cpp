#include "usual.h"

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0x3f3f3f3f));
        for (int j = 0; j < n; ++j) {
            dp[m - 1][j] = grid[m - 1][j];
        }
        for (int i = m - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][k] + grid[i][j] + moveCost[grid[i][j]][k]);
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for (int j = 0; j < n; ++j) {
            ans = min(ans, dp[0][j]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
