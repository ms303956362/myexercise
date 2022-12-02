#include "usual.h"

int dp[1005][1005][4];
vector<pair<int, int>> dirs{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

class Solution {
public:
    vector<vector<int>> ballGame(int num, vector<string>& plate) {
        memset(dp, -1, sizeof(int) * 1005 * 1005 * 4);
        int m = plate.size(), n = plate[0].size();
        function<void(int, int, int)> dfs = [&](int x, int y, int k) {
            if (dp[x][y][k] >= 0) {
                return;
            }
            if (dp[x][y][k] == -2) {
                dp[x][y][k] = -3;
                return;
            }
            if (plate[x][y] == 'O') {
                dp[x][y][k] = 0;
                return;
            }
            dp[x][y][k] = -2;
            int l = k;
            if (plate[x][y] == 'E') {
                l = (k + 3) % 4;
            } else if (plate[x][y] == 'W') {
                l = (k + 1) % 4;
            }
            auto [dx, dy] = dirs[l];
            int u = x + dx, v = y + dy;
            if (0 <= u && u < m && 0 <= v && v < n) {
                dfs(u, v, l);
                if (dp[u][v][l] >= 0) {
                    dp[x][y][k] = dp[u][v][l] + 1;
                } else if (dp[u][v][l] == -3) {
                    dp[x][y][k] = -3;
                }
            }
        };
        vector<vector<int>> ans;
        for (int i = 1; i < m - 1; ++i) {
            if (plate[i][0] == '.' && dp[i][0][3] == -1) {
                dfs(i, 0, 3);
                if (dp[i][0][3] >= 0 && dp[i][0][3] <= num) {
                    ans.push_back({i, 0});
                }
            }
            if (plate[i][n - 1] == '.' && dp[i][n - 1][1] == -1) {
                dfs(i, n - 1, 1);
                if (dp[i][n - 1][1] >= 0 && dp[i][n - 1][1] <= num) {
                    ans.push_back({i, n - 1});
                }
            }
        }
        for (int j = 1; j < n - 1; ++j) {
            if (plate[0][j] == '.' && dp[0][j][2] == -1) {
                dfs(0, j, 2);
                if (dp[0][j][2] >= 0 && dp[0][j][2] <= num) {
                    ans.push_back({0, j});
                }
            }
            if (plate[m - 1][j] == '.' && dp[m - 1][j][0] == -1) {
                dfs(m - 1, j, 0);
                if (dp[m - 1][j][0] >= 0 && dp[m - 1][j][0] <= num) {
                    ans.push_back({m - 1, j});
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
