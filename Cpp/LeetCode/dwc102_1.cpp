#include "usual.h"

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);
        for (int j = 0; j < n; ++j) {
            int len = 0;
            for (int i = 0; i < m; ++i) {
                len = max(len, (int)to_string(grid[i][j]).size());
            }
            ans[j] = len;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
