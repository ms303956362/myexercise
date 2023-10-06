#include "usual.h"

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pre_max(n), suf_max(n);
        pre_max[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre_max[i] = max(pre_max[i - 1], (long long)nums[i]);
        }
        suf_max[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suf_max[i] = max(suf_max[i + 1], (long long)nums[i]);
        }
        long long ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            ans = max(ans, (pre_max[i - 1] - nums[i]) * suf_max[i + 1]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
