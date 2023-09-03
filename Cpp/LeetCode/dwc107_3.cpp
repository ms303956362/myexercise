#include "usual.h"

class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(26, vector<int>(26, 0x3f3f3f3f)));
        dp[0][words[0].front() - 'a'][words[0].back() - 'a'] = words[0].size();
        for (int i = 1; i < n; ++i) {
            int l = words[i].size(), f = words[i].front() - 'a', b = words[i].back() - 'a';
            for (int k = 0; k < 26; ++k) {
                for (int j = 0; j < 26; ++j) {
                    if (b == j) {
                        dp[i][f][k] = min(dp[i][f][k], dp[i - 1][j][k] + l - 1);
                    } else {
                        dp[i][f][k] = min(dp[i][f][k], dp[i - 1][j][k] + l);
                    }
                }
            }
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    if (f == k) {
                        dp[i][j][b] = min(dp[i][j][b], dp[i - 1][j][k] + l - 1);
                    } else {
                        dp[i][j][b] = min(dp[i][j][b], dp[i - 1][j][k] + l);
                    }
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k < 26; ++k) {
                ans = min(ans, dp[n - 1][j][k]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> a{"ab","b"};
    Solution().minimizeConcatenatedLength(a);
    return 0;
}
