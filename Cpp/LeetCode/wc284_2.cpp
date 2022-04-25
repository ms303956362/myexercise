#include "usual.h"

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> grid(n, vector<int>(n, 1)), pre(n + 1, vector<int>(n + 1));
        for (const auto& d : dig) {
            grid[d[0]][d[1]] = 0;
        }
        pre[n][n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            pre[i][n] = pre[i + 1][n] + 1;
            pre[n][i] = pre[n][i + 1] + 1;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                pre[i][j] = grid[i][j] + pre[i + 1][j] + pre[i][j + 1] - pre[i + 1][j + 1];
            }
        }
        int ans = 0;
        for (const auto &a : artifacts) {
            int x1 = a[0], y1 = a[1], x2 = a[2], y2 = a[3];
            int sum = pre[x1][y1] - pre[x2 + 1][y1] - pre[x1][y2 + 1] + pre[x2 + 1][y2 + 1];
            if (sum == 0) {
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
