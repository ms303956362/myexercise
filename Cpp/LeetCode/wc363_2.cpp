#include "usual.h"

class Solution {
public:
    int countWays(vector<int>& nums) {
        // map<int, int> mp;
        // for (const auto& num : nums) {
        //     ++mp[num];
        // }
        // int ans = 0;
        // if (nums[0] > 0) {
        //     ans = 1;
        // }
        // int cnt = 0;
        // for (auto p = mp.begin(); p != mp.end(); ++p) {
        //     auto q = next(p);
        //     auto [num, c] = *p;
        //     cnt += c;
        //     if (cnt > num && (q == mp.end() || cnt < q->second)) {
        //         ++ans;
        //     }
        // }
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        if (nums[0] > 0) {
            ++ans;
        }
        for (int i = 0; i < n; ++i) {
            if (i + 1 > nums[i] && (i + 1 == n || i + 1 < nums[i + 1])) {
                ++ans;
            }
        }
        return ans;
    }
};