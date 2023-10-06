#include "usual.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        set<int> st, t;
        for (int i = 1; i <= k; ++i) {
            t.insert(i);
        }
        int ans = 0;
        for (const auto& num : nums) {
            if (num <= k) {
                st.insert(num);
            }
            ++ans;
            if (st == t) {
                return ans;
            }
        }
        return -1;
    }
};