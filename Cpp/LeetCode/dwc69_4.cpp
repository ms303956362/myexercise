#include "usual.h"

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> heights(m, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            int l = 0, h = 0;
            while (h < m) {
                l = h;
                int cnt = 0;
                while (h < m && grid[h][j] == 0) {
                    ++cnt;
                    ++h;
                }
                while (l < h) {
                    heights[l][j] = cnt;
                    ++l;
                }
                ++h;
            }
        }
        vector<vector<int>> widths(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            int j = 0, cnt = 0;
            while (j < n) {
                if (heights[i][j] >= stampHeight) {
                    ++cnt;
                } else {
                    cnt = 0;
                }
                widths[i][j] = cnt;
                ++j;
            }
            j = n - 1;
            cnt = 0;
            while (j >= 0) {
                widths[i][j] += cnt;
                if (heights[i][j] >= stampHeight) {
                    ++cnt;
                } else {
                    cnt = 0;
                }
                if (grid[i][j] == 0 && widths[i][j] < stampWidth)
                    return false;
                --j;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v{{1, 1, 0, 0}};
    int h = 1, w = 3;
    Solution().possibleToStamp(v, h, w);
    return 0;
}
