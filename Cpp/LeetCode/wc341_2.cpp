#include "usual.h"

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int max_cnt = 0, ans = INT_MAX;
        int n = nums.size(), m = divisors.size();
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (nums[j] % divisors[i] == 0) {
                    ++cnt;
                }
            }
            if (cnt > max_cnt || cnt == max_cnt && divisors[i] < ans) {
                max_cnt = cnt;
                ans = divisors[i];
            }
        }
        return ans;
    }
};