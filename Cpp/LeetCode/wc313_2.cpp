#include "usual.h"

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<pair<int, int>> dirs{{0, 0}, {0, 1}, {0, 2}, {1, 1}, {2, 0}, {2, 1}, {2, 2}};
        for (int i = 0; i < m - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                int sum = 0;
                for (const auto& [dx, dy] : dirs) {
                    sum += grid[i + dx][j + dy];
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
