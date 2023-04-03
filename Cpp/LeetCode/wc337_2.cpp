#include "usual.h"

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vst(m, vector<bool>(n));
        vector<tuple<int, int, int>> v;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                v.emplace_back(grid[i][j], i, j);
            }
        }
        sort(v.begin(), v.end());
        if (v[0] != make_tuple(0, 0, 0)) {
            return false;
        }
        vst[0][0] = true;
        for (int i = 1; i < n * n; ++i) {
            auto [_, x, y] = v[i];
            if (vst[x][y]) {
                return false;
            }
            auto [__, a, b] = v[i - 1];
            if (!((abs(x - a) == 1 && abs(y - b) == 2) || abs(x - a) == 2 && abs(y - b) == 1)) {
                return false;
            }
            vst[x][y] = true;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
