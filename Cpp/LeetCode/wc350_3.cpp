#include "usual.h"

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        long long mod = 1e9 + 7;
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(1 << n)));
        for (int j = 0; j < n; ++j) {
            dp[n - 1][j][1 << j] = 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int s = 0; s < (1 << n); ++s) {
                if (__builtin_popcount(s) != n - i) {
                    continue;
                }
                for (int j = 0; j < n; ++j) {
                    if (((1 << j) & s) == 0) {
                        continue;
                    }
                    for (int k = 0; k < n; ++k) {
                        if (k != j && ((1 << k) & s) && (nums[j] % nums[k] == 0 || nums[k] % nums[j] == 0)) {
                            dp[i][j][s] = (dp[i][j][s] + dp[i + 1][k][s ^ (1 << j)]) % mod;
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for (int j = 0; j < n; ++j) {
            ans = (ans + dp[0][j][(1 << n) - 1]) % mod;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{2,3,6};
    Solution().specialPerm(a);
    return 0;
}
