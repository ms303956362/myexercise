#include "usual.h"

// class Solution {
// public:
//     int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
//         int ans = 0;
//         ans += min(k, numOnes);
//         k -= min(k, numOnes);
//         k -= min(k, numZeros);
//         if (k <= 0) {
//             return ans;
//         }
//         ans -= min(k, numNegOnes);
//         return ans;
//     }
// };

// vector<bool> is_prime(1005, true);
// bool is_init = false;

// class Solution {
// public:
//     bool primeSubOperation(vector<int>& nums) {
//         if (!is_init) {
//             for (int i = 2; i <= 1000; ++i) {
//                 for (int j = 2; j < i; ++j) {
//                     if (i % j == 0) {
//                         is_prime[i] = false;
//                         break;
//                     }
//                 }
//             }
//             is_init = true;
//         }
//         int n = nums.size();
//         for (int i = 1; i < nums[0]; ++i) {
//             if (is_prime[nums[0] - i]) {
//                 nums[0] = i;
//                 break;
//             }
//         }
//         for (int i = 1; i < n; ++i) {
//             for (int j = nums[i - 1] + 1; j < nums[i]; ++j) {
//                 if (is_prime[nums[i] - j]) {
//                     nums[i] = j;
//                     break;
//                 }
//             }
//         }
//         for (int i = 1; i < n; ++i) {
//             if (nums[i] <= nums[i - 1]) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// class Solution {
// public:
//     vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
//         long long n = nums.size();
//         vector<long long> ans;
//         sort(nums.begin(), nums.end());
//         vector<long long> prep(n + 1), pren(n + 1);
//         for (int i = n - 1; i >= 0; --i) {
//             pren[i] = pren[i + 1] - (long long)nums[i];
//             prep[i] = prep[i + 1] + (long long)nums[i];
//         }
//         for (const auto& q : queries) {
//             long long k = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
//             ans.push_back(k * q - (n - k) * q + pren[0] - pren[k] + prep[k] - prep[n]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        long long n = coins.size();
        vector<vector<long long>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<long long> dp1(n), dis1(n, -1), dis2(n, -1);
        vector<unordered_set<long long>> used(n);
        function<pair<long long, long long>(long long, long long)> dfs1 = [&](long long u, long long f) {
            dis1[u] = (coins[u] == 1 ? 0 : -1);
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                auto [ans, max_dv] = dfs1(v, u);
                if (max_dv != -1) {
                    if (max_dv + 1 > dis1[u]) {
                        dis2[u] = dis1[u];
                        dis1[u] = max_dv + 1 ;
                    } else if (max_dv + 1  > dis2[u]) {
                        dis2[u] = max_dv + 1 ;
                    }
                    if (max_dv + 1 > 2) {
                        dp1[u] += ans + 2;
                        used[u].insert(v);
                    }
                }
            }
            return make_pair(dp1[u], dis1[u]);
        };
        dfs1(0, -1);
        vector<long long> dp2(n), d1(n, -1), d2(n, -1);
        dp2[0] = dp1[0];
        d1[0] = dis1[0];
        d2[0] = dis2[0];
        function<void(long long, long long)> dfs2 = [&](long long u, long long f) {
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                dp2[v] = dp1[v];
                long long dpu = dp2[u];
                if (used[u].count(v)) {
                    dpu -= dp1[v] + 2;
                }
                long long max_du = (d1[u] == dis1[v] + 1 ? (d2[u] + 1) : (d1[u] + 1));
                if (max_du > 2) {
                    dp2[v] += dpu + 2;
                }
                d1[v] = dis1[v];
                d2[v] = dis2[v];
                if (max_du > d1[v]) {
                    d2[v] = d1[v];
                    d1[v] = max_du;
                } else if (max_du > d2[v]) {
                    d2[v] = max_du;
                }
                dfs2(v, u);
            }
        };
        dfs2(0, -1);
        long long ans = 0x3f3f3f3f;
        for (long long i = 0; i < n; ++i) {
            ans = min(ans, dp2[i]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> coins{1,0,0,0,0,1};
    vector<vector<int>> edges{{0,1},{1,2},{2,3},{3,4},{4,5}};
    Solution().collectTheCoins(coins, edges);
    return 0;
}