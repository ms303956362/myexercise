#include "usual.h"

// class Solution {
// public:
//     int totalSteps(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> pre(n + 1), r(n, n), dp(n + 1);
//         pre[n - 1] = 1;
//         for (int i = n - 2; i >= 0; --i) {
//             if (nums[i] <= nums[i + 1]) {
//                 pre[i] = pre[i + 1] + 1;
//             } else {
//                 pre[i] = pre[i + 1];
//             }
//         }
//         stack<int> s;
//         for (int i = n - 1; i >= 0; --i) {
//             while (!s.empty() && nums[s.top()] < nums[i]) {
//                 s.pop();
//             }
//             if (!s.empty()) {
//                 r[i] = s.top();
//             }
//             s.push(i);
//         }
//         for (int i = n - 1; i >= 0; --i) {
//             dp[i] = max(dp[r[i]], pre[i + 1] - pre[r[i]]);
//         }
//         return dp[0];
//     }
// };

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        vector<int> r(n, n);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                r[i] = s.top();
            }
            s.push(i);
        }
        int ans = 0;
        
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
