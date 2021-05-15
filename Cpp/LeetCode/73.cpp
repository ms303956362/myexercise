#include "usual.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool col1st = false, row1st = false;
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                if (matrix[i][j] == 0) {
                    if (i == 0)
                        row1st = true;
                    if (j == 0)
                        col1st = true;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i != n; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j != m; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j != m; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i != n; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row1st)
            for (int j = 0; j != m; ++j) {
                matrix[0][j] = 0;
            }
        if (col1st)
            for (int i = 0; i != n; ++i)
                matrix[i][0] = 0;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> a{{-4,-2147483648,6,-7,0},{-8,6,-8,-6,0},{2147483647,2,-9,-6,-10}};
    Solution().setZeroes(a);
    return 0;
}
