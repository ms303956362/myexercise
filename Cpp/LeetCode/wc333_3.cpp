#include "usual.h"

using ll = long long;

class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        ll mod = 1e9 + 7;
        int n = nums.size();
        vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> idx(30);
        int m = primes.size();
        for (int i = 0; i < m; ++i) {
            idx[primes[i]] = i;
        }
        vector<vector<ll>> dp(n + 1, vector<ll>(1 << m));
        dp[n][0] = 1;
        sort(nums.begin(), nums.end());
        int i = n - 1;
        for (i = n - 1; i >= 0 && nums[i] > 1; --i) {
            dp[i] = dp[i + 1];
            int t = 0;
            bool ok = true;
            for (const auto& p : primes) {
                if (nums[i] % p == 0) {
                    if ((nums[i] / p) % p == 0) {
                        ok = false;
                        break;
                    }
                    t |= (1 << idx[p]);
                }
            }
            if (!ok) {
                continue;
            }
            for (int s = 0; s < (1 << m); ++s) {
                if ((s & t) == t) {
                    dp[i][s] = (dp[i][s] + dp[i + 1][s ^ t]) % mod;
                }
            }
        }
        ll ans = 0;
        for (int s = 0; s < (1 << m); ++s) {
            ans = (ans + dp[i + 1][s]) % mod;
        }
        ll p = 1;
        for (int j = 0; j <= i; ++j) {
            p = (p * 2) % mod;
        }
        ans = ((ans * p % mod - 1) % mod + mod) % mod;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{3,4,4,5};
    Solution().squareFreeSubsets(v);
    return 0;
}
