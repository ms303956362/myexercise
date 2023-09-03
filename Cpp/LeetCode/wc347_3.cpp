#include "usual.h"

class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();
        vector<vector<long long>> dp1(n, vector<long long>(2, 0x3f3f3f3f3f3f3f3f)), dp2(n, vector<long long>(2, 0x3f3f3f3f3f3f3f3f));
        dp1[0][0] = (s[0] == '1');
        dp1[0][1] = (s[0] == '0');
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                dp1[i][0] = dp1[i - 1][0];
                dp1[i][1] = dp1[i - 1][0] + i + 1;
            } else {
                dp1[i][0] = dp1[i - 1][1] + i + 1;
                dp1[i][1] = dp1[i - 1][1];
            }
        }
        dp2[n - 1][0] = (s[n - 1] == '1');
        dp2[n - 1][1] = (s[n - 1] == '0');
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == '0') {
                dp2[i][0] = dp2[i + 1][0];
                dp2[i][1] = dp2[i + 1][0] + n - i;
            } else {
                dp2[i][0] = dp2[i + 1][1] + n - i;
                dp2[i][1] = dp2[i + 1][1];
            }
        }
        long long ans = min({dp2[0][0], dp2[0][1], dp1[n - 1][0], dp1[n - 1][1]});
        for (int i = 0; i < n - 1; ++i) {
            ans = min({ans, dp1[i][0] + dp2[i + 1][0], dp1[i][1] + dp2[i + 1][1]});
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s("010101");
    Solution().minimumCost(s);
    return 0;
}
