#include "usual.h"

class Solution {
public:
    int numSubmat(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int cnt = 0;
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m, 0))));
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                dp[0][0][i][j] = a[i][j];
                cnt += a[i][j];
            }
        }
        for (int r = 0; r != n; ++r) {
            for (int c = (r == 0 ? 1 : 0); c != m; ++c) {
                for (int i = r; i != n; ++i) {
                    for (int j = c; j != m;++j) {
                        if (c == 0) {
                            if (dp[r - 1][c][i - 1][j] && dp[0][c][i][j]) {
                                dp[r][c][i][j] = 1;
                                ++cnt;
                            }
                        } else {
                            if (dp[r][c - 1][i][j - 1] && dp[r][0][i][j]) {
                                dp[r][c][i][j] = 1;
                                ++cnt;
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v{{1, 0, 1}, { 1, 1, 0 }, { 1, 1, 0 }};
    Solution().numSubmat(v);
    return 0;
}
