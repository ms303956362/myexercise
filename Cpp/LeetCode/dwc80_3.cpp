#include "usual.h"

bool dp[5001][5001];
bool has[101][101];
class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        if (s == sub) {
            return true;
        }
        int m = s.size(), n = sub.size();
        memset(dp, false, sizeof(bool) * 5001 * 5001);
        memset(has, false, sizeof(bool) * 101 * 101);
        for (int i = 0; i <= m; ++i) {
            dp[i][n] = true;
        }
        for (const auto& mp : mappings) {
            int k1 = getIndex(mp[0]), k2 = getIndex(mp[1]);
            has[k1][k2] = true;
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int k1 = getIndex(sub[j]), k2 = getIndex(s[i]);
                if ((sub[j] == s[i] || has[k1][k2]) && dp[i + 1][j + 1]) {
                    dp[i][j] = true;
                }
            }
            if (dp[i][0]) {
                return true;
            }
        }
        return false;
    }

    inline int getIndex(char c) {
        if ('a' <= c && c <= 'z') {
            return c - 'a';
        } else if ('A' <= c && c <= 'Z') {
            return c - 'A' + 30;
        }
        return c - '0' + 60;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> v{{ 'e', '3' }, { 't', '7' }, { 't', '8' }};
    Solution().matchReplacement("fool3e7bar", "leet", v);
    return 0;
}
