#include "usual.h"

class Solution {
public:
    long long appealSum(string s) {
        long long n = s.size();
        vector<long long> dp(n), last_idx(26, -1);
        last_idx[s[0] - 'a'] = 0;
        dp[0] = 1;
        for (long long i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + i - last_idx[s[i] - 'a'];
            last_idx[s[i] - 'a'] = i;
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += dp[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
