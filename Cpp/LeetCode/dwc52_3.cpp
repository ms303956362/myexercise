#include "usual.h"

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        for (int k = 0; k < n; ++k) {
            int i = m - 1, j = m - 1;
            while (i >= 0) {
                if (box[k][i] == '*')
                    j = i - 1;
                else if (box[k][i] == '#') {
                    box[k][i] = '.';
                    box[k][j] = '#';
                    --j;
                }
                --i;
            }
        }
        vector<vector<char>> ans(m, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                ans[j][m - 1 - i] = box[i][j];
        }
        return ans;
    }
};