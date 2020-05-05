#include "usual.h"

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int MOD = 1000000007;
        vector<vector<vector<int>>> v(11, vector<vector<int>>(41, vector<int>(41, 0)));
        int n = hats.size();
        for (int i = 1; i != 41; ++i){
            for (int j = 1; j != 41; ++j) {
                v[n][i][j] = 1;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            int m = hats[i].size();
            for (int j = 0; j != m; ++j) {
                for (int k = 1; k != 41; ++k) {
                    if (k == hats[i][j])
                        continue;
                    for (int y = 0; y != 41; ++y) {
                        if (y == k)
                            continue;
                        for (int l = 1; l != 41; ++l)
                        {
                            if (l == k)
                                continue;
                            v[i][hats[i][j]][k] += v[i + 1][y][l];
                            v[i][hats[i][j]][k] %= MOD;
                        }
                    }
                }
            }
        }
        int res = 0;
        int m = hats[0].size();
        for (int j = 0; j != m; ++j) {
            for (int k = 1; k != 41; ++k) {
                res += v[0][hats[0][j]][k];
                res %= MOD;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    // Solution().numberWays
    return 0;
}
