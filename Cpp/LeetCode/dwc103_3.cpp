#include "usual.h"

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vst(m, vector<bool>(n));
        vector<pair<int, int>> dirs{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        function<int(int, int)> dfs = [&](int i, int j) {
            int sum = grid[i][j];
            vst[i][j] = true;
            for (const auto& [dx, dy] : dirs) {
                int x = i + dx, y = j + dy;
                if (0 <= x && x < m && 0 <= y && y < n && grid[x][y] > 0 && !vst[x][y]) {
                    sum += dfs(x, y);
                }
            }
            return sum;
        };
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};