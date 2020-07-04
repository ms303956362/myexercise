#include "usual.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if (nums.size() == 1)
            return (nums[0] == 1) ? 1 : 0;
        vector<int> cnt;
        int cnt1 = (nums[0] == 1 ? 1 : 0), cnt0 = (nums[0] == 0 ? 1 : 0);
        int res = INT_MIN;
        int last = nums[0];
        for (int i = 1; i != nums.size(); ++i) {
            if (nums[i] == 1) {
                if (last == 0) {
                    if (cnt0 == 1 && !cnt.empty()) {
                        cnt.push_back(0);
                    }
                    last = 1;
                    cnt1 = 1;
                } else {
                    ++cnt1;
                }
            } else {
                if (last == 1) {
                    cnt.push_back(cnt1);
                    last = 0;
                    cnt0 = 1;
                } else {
                    ++cnt0;
                }
            }
        }
        if (last == 1) {
            cnt.push_back(cnt1);
            last = 0;
            cnt0 = 1;
        }
        if (cnt.size() == 0)
            return 0;
        for (int i = 0; i != cnt.size(); ++i) {
            if (cnt[i]) {
                res = max(res, cnt[i]);
            } else {
                res = max(res, cnt[i - 1] + cnt[i + 1]);
            }
        }
        return res;
    }
};