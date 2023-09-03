#include "usual.h"

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> idx(m * n + 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                idx[mat[i][j]] = make_pair(i, j);
            }
        }
        vector<int> cntr(m), cntc(n);
        for (int k = 0; k < m * n; ++k) {
            int num = arr[k];
            auto [i, j] = idx[num];
            ++cntc[j];
            ++cntr[i];
            if (cntc[j] == m || cntr[i] == n) {
                return k;
            }
        }
        return -1;
    }
};
