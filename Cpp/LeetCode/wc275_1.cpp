#include "usual.h"

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            vector<bool> vst(n + 1);
            for (int j = 0; j < n; ++j) {
                if (1 <= matrix[i][j] && matrix[i][j] <= n && !vst[matrix[i][j]]) {
                    vst[matrix[i][j]] = true;
                } else {
                    return false;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            vector<bool> vst(n + 1);
            for (int i = 0; i < n; ++i) {
                if (1 <= matrix[i][j] && matrix[i][j] <= n && !vst[matrix[i][j]]) {
                    vst[matrix[i][j]] = true;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
