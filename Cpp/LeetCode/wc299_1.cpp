#include "usual.h"

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid[0].size();
        for (int i = 0; i < n; ++i) {
            if (grid[i][i] == 0) {
                return false;
            }
            if (grid[i][n - i - 1] == 0) {
                return false;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && i + j != n - 1 && grid[i][j] != 0) {
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
