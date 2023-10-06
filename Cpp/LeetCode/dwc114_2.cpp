#include "usual.h"

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (const auto& num : nums) {
            ++cnt[num];
        }
        int ans = 0;
        for (const auto& [_, c] : cnt) {
            if (c == 1) {
                return -1;
            }
            if (c % 3 == 0) {
                ans += c / 3;
            } else if (c % 3 == 2) {
                ans += c / 3 + 1;
            } else {
                ans += (c - 2) / 3 + 2;
            }
        }
        return ans;
    }
};