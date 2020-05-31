#include "usual.h"

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
        for (int i = 0; i != c; ++i) {
            dp[r - 1][i][i] = grid[r - 1][i];
            for (int j = i + 1; j != c; ++j) {
                dp[r - 1][i][j] = grid[r - 1][i] + grid[r - 1][j];
                dp[r - 1][j][i] = grid[r - 1][i] + grid[r - 1][j];
            }
        }
        for (int k = r - 2; k >= 0; --k){
            for (int i = 0; i != c; ++i) {
                for (int j = i; j != c; ++j) {
                    if (i == j)
                        dp[k][i][j] = grid[k][i];
                    else
                        dp[k][i][j] = grid[k][i] + grid[k][j];
                    int max_ij = 0;
                    for (int p = max(j - 1, 0); p <= min(j + 1, c - 1); ++p) {
                        for (int q = max(i - 1, 0); q <= min(i + 1, p); ++q) {
                            max_ij = max(max_ij, dp[k + 1][q][p]);
                        }
                    }
                    dp[k][i][j] += max_ij;
                    dp[k][j][i] = dp[k][i][j];
                }
            }
        }
        return dp[0][0][c - 1];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
