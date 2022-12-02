#include "usual.h"

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> cnt(32);
        int n = nums.size();
        int i = n - 1, j = n - 1;
        auto check = [&](int j) {
            for (int k = 0; k < 32; ++k) {
                if ((nums[j] & (1 << k)) && cnt[k] <= 1) {
                    return false;
                }
            }
            return true;
        };
        vector<int> ans(n);
        while (i >= 0) {
            for (int k = 0; k < 32; ++k) {
                if (nums[i] & (1 << k)) {
                    ++cnt[k];
                }
            }
            while (j > i && check(j)) {
                for (int k = 0; k < 32; ++k) {
                    if (nums[j] & (1 << k)) {
                        --cnt[k];
                    }
                }
                --j;
            }
            ans[i] = j - i + 1;
            --i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
