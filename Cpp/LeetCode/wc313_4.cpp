#include "usual.h"

class Solution {
public:
    int deleteString(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        vector<vector<int>> max_len(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    max_len[i][j] = max_len[i + 1][j + 1] + 1;
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i + 1; j <= n; ++j) {
                if (max_len[i][j] >= j - i) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[0];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
