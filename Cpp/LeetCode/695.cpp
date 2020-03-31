#include "usual.h"

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0, max_area = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                if (grid[i][j] == 1) {
                    area = dfs(i, j, grid);
                    if (area > max_area)
                        max_area = area;
                }
            }
        }
        return max_area;
    }

    int dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 0;
        int area = 1;
        int n = grid.size(), m = grid[0].size();
        if (i - 1 >= 0 && grid[i - 1][j] == 1)
            area += dfs(i - 1, j, grid);
        if (i + 1 < n && grid[i + 1][j] == 1)
            area += dfs(i + 1, j, grid);
        if (j - 1 >= 0 && grid[i][j - 1] == 1)
            area += dfs(i, j - 1, grid);
        if (j + 1 < m && grid[i][j + 1] == 1)
            area += dfs(i, j + 1, grid);
        return area;
    }
};

int main(int argc, char const *argv[])
{
    // vector<vector<int>> g{{0,1,0,0,1},
    //                       {1,1,0,1,0},
    //                       {0,0,1,1,1},
    //                       {0,1,1,0,0},
    //                       {1,1,1,0,0}};
    vector<vector<int>> g{{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
                          { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
                          { 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
                          { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0 },
                          { 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0 },
                          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
                          { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
                          { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 }};
    Solution s;
    cout << s.maxAreaOfIsland(g) << endl;
    return 0;
}
