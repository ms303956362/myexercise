#include "usual.h"

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i - 1][j - 1]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i - 1][j]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i - 1][j + 1]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i][j - 1]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i][j]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i][j + 1]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i + 1][j - 1]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i + 1][j]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i + 1][j + 1]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
