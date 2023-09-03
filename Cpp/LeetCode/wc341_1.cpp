#include "usual.h"

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans{0, 0};
        for (int i = 0; i < m; ++i) {
            int cnt1 = 0;
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    ++cnt1;
                }
            }
            if (cnt1 > ans[1]) {
                ans[0] = i;
                ans[1] = cnt1;
            }
        }
        return ans;
    }
};