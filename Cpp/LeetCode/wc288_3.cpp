#include "usual.h"

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (const auto& num : nums) {
            q.push(num);
        }
        for (int i = 0; i < k; ++i) {
            int num = q.top();
            q.pop();
            q.push(num + 1);
        }
        long long ans = 1, mod = 1e9 + 7;
        while (!q.empty()) {
            long long num = q.top();
            q.pop();
            ans = (ans * num) % mod;
        }
        return ans;
    }
};