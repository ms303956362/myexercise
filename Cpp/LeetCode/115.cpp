#include "usual.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if (n < m)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        dp[n][m] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= max(m - (n - i), 0); --j) {
                dp[i][j] = dp[i + 1][j];
                if (s[i] == t[j])
                    dp[i][j] += dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};

int main(int argc, char const *argv[])
{
    string s("babgbag"), t("bag");
    Solution().numDistinct(s, t);
    return 0;
}
