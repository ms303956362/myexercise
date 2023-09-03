#include "usual.h"

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> conv(n);
        long long max_num = 0;
        conv[0] = 2 * nums[0];
        max_num = nums[0];
        for (int i = 1; i < n; ++i) {
            max_num = max(max_num, (long long)nums[i]);
            conv[i] = nums[i] + max_num;
        }
        vector<long long> ans(n);
        ans[0] = conv[0];
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] + conv[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
