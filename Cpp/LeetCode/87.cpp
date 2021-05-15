#include "usual.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n, false)));
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != n; ++j) {
                if (s1[i] == s2[j])
                    dp[0][i][j] = true;
            }
        }
        for (int l = 1; l != n; ++l) {
            for (int i = 0; i <= n - l - 1; ++i) {
                for (int j = 0; j <= n - l - 1; ++j) {
                    for (int k = 0; k != l; ++k) {
                        if ((dp[k][i][j] && dp[l - k - 1][i + k + 1][j + k + 1]) || (dp[k][i][j + l - k] && dp[l - k - 1][i + k + 1][j]))
                            dp[l][i][j] = true;
                    }
                }
            }
        }
        return dp[n - 1][0][n - 1];
    }
};

int main(int argc, char const *argv[])
{
    string s1("great"), s2("rgeat");
    Solution().isScramble(s1, s2);
    return 0;
}
