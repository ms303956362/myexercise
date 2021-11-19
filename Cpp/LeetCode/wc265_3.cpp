#include "usual.h"

// class Solution {
// public:
//     int minimumOperations(vector<int>& nums, int start, int goal) {
//         int n = nums.size();
//         vector<vector<int>> dp(n + 1, vector<int>(1001, 0x3f3f3f3f));
//         dp[0][start] = 0;
//         int ans = INT_MAX;
//         for (int i = 1; i <= n; ++i) {
//             queue<int> q;
//             q.push(start);
//             while (!q.empty()) {
//                 int x = q.front();
//                 q.pop();
//                 dp[i][x] = dp[i - 1][x];
//                 if (0 <= x - nums[i - 1] && x - nums[i - 1] <= 1000) {
//                     dp[i][x - nums[i - 1]] = min(dp[i][x - nums[i - 1]], dp[i][x] + 1);
//                     q.push(x - nums[i - 1]);
//                 }
//                 if (0 <= x + nums[i - 1] && x + nums[i - 1] <= 1000) {
//                     dp[i][x + nums[i - 1]] = min(dp[i][x + nums[i - 1]], dp[i][x] + 1);
//                     q.push(x + nums[i - 1]);
//                 }
//                 if (0 <= (x ^ nums[i - 1]) && (x ^ nums[i - 1]) <= 1000) {
//                     dp[i][x ^ nums[i - 1]] = min(dp[i][x ^ nums[i - 1]], dp[i][x] + 1);
//                     q.push(x ^ nums[i - 1]);
//                 }
//                 if (x - nums[i - 1] == goal || x + nums[i - 1] == goal || (x ^ nums[i - 1]) == goal)
//                     ans = min(ans, dp[i][x] + 1);
//             }
//         }
//         return ans == INT_MAX ? -1 : ans;
//     }
// };

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        queue<int> q;
        vector<bool> vst(1001, false);
        q.push(start);
        vst[start] = true;
        int ans = 0;
        while (!q.empty()) {
            int l = q.size();
            ++ans;
            for (int i = 0; i < l; ++i) {
                auto u = q.front();
                q.pop();
                for (const auto& num : nums) {
                    int v = u + num;
                    if (v == goal) {
                        return ans;
                    } else if (0 <= v && v <= 1000 && !vst[v]) {
                        vst[v] = true;
                        q.push(v);
                    }
                    v = u - num;
                    if (v == goal) {
                        return ans;
                    } else if (0 <= v && v <= 1000 && !vst[v]) {
                        vst[v] = true;
                        q.push(v);
                    }
                    v = u ^ num;
                    if (v == goal) {
                        return ans;
                    } else if (0 <= v && v <= 1000 && !vst[v]) {
                        vst[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
