#include "usual.h"

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = i - 1, y = j - 1;
                set<int> s1, s2;
                while (0 <= x && x < m && 0 <= y && y < n) {
                    s1.insert(grid[x][y]);
                    --x;
                    --y;
                }
                x = i + 1;
                y = j + 1;
                while (0 <= x && x < m && 0 <= y && y < n) {
                    s2.insert(grid[x][y]);
                    ++x;
                    ++y;
                }
                ans[i][j] = abs((int)s1.size() - (int)s2.size());
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
