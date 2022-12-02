#include "usual.h"

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (!(grid[0][0] == '(' && grid[m - 1][n - 1] == ')')) {
            return false;
        }
        vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n));
        dp[m - 1][n - 1].insert(-1);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int inc = grid[i][j] == '(' ? 1 : -1;
                if (i + 1 < m) {
                    for (const auto& cnt : dp[i + 1][j]) {
                        if (cnt + inc <= 0) {
                            dp[i][j].insert(cnt + inc);
                        }
                    }
                }
                if (j + 1 < n) {
                    for (const auto& cnt : dp[i][j + 1]) {
                        if (cnt + inc <= 0) {
                            dp[i][j].insert(cnt + inc);
                        }
                    }
                }
            }
        }
        return dp[0][0].count(0);
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> g{{ '(', '(', '(' }, { ')', '(', ')' }, { '(', '(', ')' }, { '(', '(', ')' }};
    Solution().hasValidPath(g);
    return 0;
}
