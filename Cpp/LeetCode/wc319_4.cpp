#include "usual.h"

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> dp(n + 5, vector<bool>(n + 5, true));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = true;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            }
        }
        vector<int> dp2(n + 5);
        for (int i = n - 1; i >= 0; --i) {
            dp2[i] = dp2[i + 1];
            for (int j = i + k - 1; j < n; ++j) {
                if (dp[i][j]) {
                    dp2[i] = max(dp2[i], dp2[j + 1] + 1);
                }
            }
        }
        return dp2[0];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
