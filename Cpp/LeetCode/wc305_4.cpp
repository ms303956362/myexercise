#include "usual.h"

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(26);
        for (int i = n - 1; i >= 0; --i) {
            dp[s[i] - 'a'] = dp[s[i] - 'a'] + 1;
            for (int c = max(0, s[i] - 'a' - k); c <= min(25, s[i] -'a' + k); ++c) {
                if (c == s[i] - 'a') {
                    continue;
                }
                dp[s[i] - 'a'] = max(dp[s[i] - 'a'], dp[c] + 1);
            }
        }
        int ans = 0;
        for (int c = 0; c <= 25; ++c) {
            ans = max(ans, dp[c]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution().longestIdealString("jxhwaysa", 14);
    return 0;
}
