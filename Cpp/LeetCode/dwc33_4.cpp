#include "usual.h"

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> dxdy{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> vst(n, vector<int>(m, 0));
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                if (!vst[i][j] && dfs(i, j, n, m, grid, vst, 1, dxdy))
                    return true;
            }
        }
        return false;
    }

    bool dfs(int i, int j, int n, int m, vector<vector<char>>& g, vector<vector<int>>& vst, int level, vector<pair<int, int>>& dxdy) {
        vst[i][j] = level;
        int x, y;
        for (const auto&[dx, dy] : dxdy) {
            x = i + dx;
            y = j + dy;
            if (x < 0 || x >= n || y < 0 || y >= m || g[i][j] != g[x][y])
                continue;
            if (vst[x][y] && (vst[i][j] - vst[x][y] >= 3))
                return true;
            else if (!vst[x][y] && dfs(x, y, n, m, g, vst, level + 1, dxdy))
                return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> c{{ 'a', 'a', 'a', 'a' }, { 'a', 'b', 'b', 'a' }, { 'a', 'b', 'b', 'a' }, { 'a', 'a', 'a', 'a' }};
    Solution().containsCycle(c);
    return 0;
}
