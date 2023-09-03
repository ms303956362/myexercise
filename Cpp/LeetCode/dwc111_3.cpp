#include "usual.h"

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), ans = n;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                int cnt = 0;
                for (int k = 0; k < n; ++k) {
                    int target = 1;
                    if (k < i) {
                        target = 1;
                    } else if (k < j) {
                        target = 2;
                    } else {
                        target = 3;
                    }
                    if (target != nums[k]) {
                        ++cnt;
                    }
                }
                ans = min(ans, cnt);
            }
        }
        return ans;
    }
};
