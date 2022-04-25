#include "usual.h"

class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f2(m, vector<int>(n)), f5(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int num = grid[i][j];
                while (num % 2 == 0) {
                    ++f2[i][j];
                    num /= 2;
                }
                while (num % 5 == 0) {
                    ++f5[i][j];
                    num /= 5;
                }
            }
        }
        vector<vector<vector<int>>> cnt2(m, vector<vector<int>>(n, vector<int>(4))), cnt5(m, vector<vector<int>>(n, vector<int>(4)));
        for (int j = 0; j < n; ++j) {
            for (int i = 1; i < m; ++i) {
                cnt2[i][j][0] = cnt2[i - 1][j][0] + f2[i - 1][j];
                cnt5[i][j][0] = cnt5[i - 1][j][0] + f5[i - 1][j];
            }
            for (int i = m - 2; i >= 0; --i) {
                cnt2[i][j][1] = cnt2[i + 1][j][1] + f2[i + 1][j];
                cnt5[i][j][1] = cnt5[i + 1][j][1] + f5[i + 1][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                cnt2[i][j][2] = cnt2[i][j - 1][2] + f2[i][j - 1];
                cnt5[i][j][2] = cnt5[i][j - 1][2] + f5[i][j - 1];
            }
            for (int j = n - 2; j >= 0; --j) {
                cnt2[i][j][3] = cnt2[i][j + 1][3] + f2[i][j + 1];
                cnt5[i][j][3] = cnt5[i][j + 1][3] + f5[i][j + 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int max_cnt = 0;
                for (int k1 = 0; k1 < 2; ++k1) {
                    for (int k2 = 2; k2 < 4; ++k2) {
                        max_cnt = max(max_cnt, min(cnt2[i][j][k1] + cnt2[i][j][k2] + f2[i][j], cnt5[i][j][k1] + cnt5[i][j][k2] + f5[i][j]));
                    }
                }
                ans = max(ans, max_cnt);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
