#include "usual.h"

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> trans(grid.begin(), grid.end());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(trans[i][j], trans[j][i]);
            }
        }
        sort(grid.begin(), grid.end());
        sort(trans.begin(), trans.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i] == trans[j]) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
