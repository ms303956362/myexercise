#include "usual.h"

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> idx(32);
        for (int i = 0; i < m; ++i) {
            int s = 0;
            for (int j = 0; j < n; ++j) {
                s |= (grid[i][j] << j);
            }
            if (s == 0) {
                return {i};
            }
            idx[s].push_back(i);
        }
        for (int i = 0; i < 32; ++i) {
            for (int j = i + 1; j < 32; ++j) {
                if ((i & j) == 0 && !idx[i].empty() && !idx[j].empty()) {
                    vector<int> ans{idx[i][0], idx[j][0]};
                    sort(ans.begin(), ans.end());
                    return ans;
                }
            }
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
