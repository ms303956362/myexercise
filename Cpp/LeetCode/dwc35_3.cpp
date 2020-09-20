#include "usual.h"

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        unordered_map<int, int> m;
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = (pre[i - 1] + nums[i - 1]) % p;
        }
        if (pre[n] == 0)
            return 0;
        int ans = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            int target = (pre[i] - pre[n] + p) % p;
            auto q = m.find(target);
            if (q != m.end()) {
                ans = min(ans, i - q->second);
            }
            m.emplace(pre[i], i);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{6, 3, 5, 2};
    int p = 9;
    Solution().minSubarray(nums, p);
    return 0;
}
