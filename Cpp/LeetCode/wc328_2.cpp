#include "usual.h"

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 1, vector<int>(n + 1));
        for (const auto& q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            diff[r1][c1] += 1;
            diff[r1][c2 + 1] -= 1;
            diff[r2 + 1][c1] -= 1;
            diff[r2 + 1][c2 + 1] += 1;
        }
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = diff[i][j];
                if (i - 1 >= 0) {
                    ans[i][j] += ans[i - 1][j];
                }
                if (j - 1 >= 0) {
                    ans[i][j] += ans[i][j - 1];
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    ans[i][j] -=  ans[i - 1][j - 1];
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
