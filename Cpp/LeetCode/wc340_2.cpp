#include "usual.h"

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> suf_sum, suf_cnt;
        vector<long long> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            suf_sum[nums[i]] += i;
            ++suf_cnt[nums[i]];
            ans[i] += suf_sum[nums[i]] - suf_cnt[nums[i]] * i;
        }
        map<int, long long> pre_sum, pre_cnt;
        for (int i = 0; i < n; ++i) {
            pre_sum[nums[i]] += i;
            ++pre_cnt[nums[i]];
            ans[i] += pre_cnt[nums[i]] * i - pre_sum[nums[i]];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
