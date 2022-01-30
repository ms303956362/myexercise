#include "usual.h"

class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> left(m, vector<int>(n)), right(m, vector<int>(n)), dp(m, vector<int>(n));
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (grid[m - 1][j] == 1) {
                left[m - 1][j] = 1;
                right[m - 1][j] = 1;
                dp[m - 1][j] = 1;
            }
        }
        for (int i = m - 2; i >= 0; --i) {
            if (grid[i][0] == 1)
                left[i][0] = 1;
            if (grid[i][n - 1] == 1)
                right[i][n - 1] = 1;
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 0)
                    continue;
                right[i][j] = right[i + 1][j + 1] + 1;
                left[i][j] = left[i + 1][j - 1] + 1;
                dp[i][j] = min({dp[i + 1][j] + 1, left[i][j], right[i][j]});
                if (dp[i][j] > 1)
                    ans += dp[i][j] - 1;
            }
        }
        left = vector<vector<int>>(m, vector<int>(n));
        right = vector<vector<int>>(m, vector<int>(n));
        dp = vector<vector<int>> (m, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 1) {
                left[0][j] = 1;
                right[0][j] = 1;
                dp[0][j] = 1;
            }
        }
        for (int i = 1; i < m; ++i) {
            if (grid[i][0] == 1)
                left[i][0] = 1;
            if (grid[i][n - 1] == 1)
                right[i][n - 1] = 1;
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 0)
                    continue;
                right[i][j] = right[i - 1][j + 1] + 1;
                left[i][j] = left[i - 1][j - 1] + 1;
                dp[i][j] = min({dp[i - 1][j] + 1, left[i][j], right[i][j]});
                if (dp[i][j] > 1)
                    ans += dp[i][j] - 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
