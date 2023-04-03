#include "usual.h"

// bool has[1005];
// int nums[25];

// class Solution {
// public:
//     int beautifulSubsets(vector<int>& a, int k) {
//         int n = a.size();
//         for (int i = 0; i < n; ++i) {
//             nums[i] = a[i];
//         }
//         memset(has, false, sizeof(bool) * 1005);
//         int ans = 0;
//         for (int s = 1; s < (1 << n); ++s) {
//             for (int i = 0; i < n; ++i) {
//                 if (s & (1 << i)) {
//                     has[nums[i]] = true;
//                 }
//             }
//             bool ok = true;
//             for (int i = 0; i < n; ++i) {
//                 if (s & (1 << i)) {
//                     int num1 = nums[i] - k, num2 = nums[i] + k;
//                     if (0 <= num1 && num1 < 1005 && has[num1]) {
//                         ok = false;
//                         break;
//                     }
//                     if (0 <= num2 && num2 < 1005 && has[num2]) {
//                         ok = false;
//                         break;
//                     }
//                 }
//             }
//             ans += ok;
//             for (int i = 0; i < n; ++i) {
//                 if (s & (1 << i)) {
//                     has[nums[i]] = false;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<vector<int>> a(k);
        for (const auto& num : nums) {
            a[num % k].push_back(num);
        }
        int ans = 1;
        for (int i = 0; i < k; ++i) {
            sort(a[i].begin(), a[i].end());
            int l = a[i].size();
            if (l == 0) {
                continue;
            }
            vector<vector<int>> dp(l, vector<int>(2));
            dp[l - 1][0] = 1;
            dp[l - 1][1] = 1;
            for (int j = l - 2; j >= 0; --j) {
                if (a[i][j] + k == a[i][j + 1]) {
                    int t = j + 1;
                    while (t < l && a[i][t] == a[i][j] + k) {
                        ++t;
                    }
                    if (t < l) {
                        dp[j][1] = dp[t][0] + dp[t][1];
                    }
                } else {
                    dp[j][1] = dp[j + 1][0] + dp[j + 1][1];
                }
                dp[j][0] = dp[j + 1][0] + dp[j + 1][1];
            }
            ans *= (dp[0][0] + dp[0][1]);
        }
        --ans;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{1,2,3,3};
    int k = 1;
    Solution().beautifulSubsets(a, k);
    return 0;
}
