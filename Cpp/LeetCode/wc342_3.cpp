#include "usual.h"

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> cnt(101);
        for (int i = 0; i < k; ++i) {
            ++cnt[nums[i] + 50];
        }
        vector<int> ans;
        for (int i = k; i <= n; ++i) {
            vector<int> pre(101);
            pre[0] = cnt[0];
            for (int j = 1; j < 101; ++j) {
                pre[j] = pre[j - 1] + cnt[j];
            }
            int j = lower_bound(pre.begin(), pre.end(), x) - pre.begin();
            if (nums[j] < 0) {
                ans.push_back(nums[j]);
            } else {
                ans.push_back(0);
            }
            if (i < n) {
                --cnt[nums[i - k] + 50];
                ++cnt[nums[i] + 50];
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
