#include "usual.h"

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        vector<unsigned int> dp(n + 1, k + 1);
        dp[0] = 0;
        for (int i = n - 1; i >= 0; --i) {
            int d = s[i] - '0';
            for (int j = n; j > 0; --j) {
                if (d == 0) {
                    dp[j] = min(dp[j], dp[j - 1]);
                } else if (j <= 32) {
                    dp[j] = min(dp[j], dp[j - 1] + (d << (j - 1)));
                }
            }
        }
        for (int j = n; j >= 0; --j) {
            if (dp[j] <= k) {
                return j;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    string s("001010101011010100010101101010010");
    int k = 93951055;
    Solution().longestSubsequence(s, k);
    return 0;
}
