#include "usual.h"

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long ans = 1, n = nums.size(), i = 0, j = n - 1, mod = 1e9 + 7;
        while (i < n && nums[i] == 0) {
            ++i;
        }
        while (j >= 0 && nums[j] == 0) {
            --j;
        }
        if (j < i) {
            return 0;
        }
        int k = i + 1;
        while (k < j) {
            long long cnt = 1;
            while (k < j && nums[k] != 1) {
                ++cnt;
                ++k;
            }
            ans = (ans * cnt) % mod;
            ++k;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
