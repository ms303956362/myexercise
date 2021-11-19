#include "usual.h"

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m, vector<int>(n));
        int k = 0, l = original.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (k < l) {
                    ans[i][j] = original[k];
                    ++k;
                } else {
                    return {};
                }
            }
        }
        if (k < l)
            return {};
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
