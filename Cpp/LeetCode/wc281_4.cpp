#include "usual.h"

class Solution {
public:
    long long coutPairs(vector<int>& nums, int k) {
        vector<long long> cnt(max(*max_element(nums.begin(), nums.end()), k) + 1);
        int n = nums.size();
        long long ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            int f1 = __gcd(k, nums[i]), f2 = k / f1;
            ans += cnt[f2];
            for (int j = 1; j <= sqrt(nums[i]); ++j) {
                if (nums[i] % j == 0) {
                    ++cnt[j];
                    if (j != nums[i] / j)
                        ++cnt[nums[i] / j];
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{1, 2, 3, 4, 5};
    int k = 2;
    Solution().coutPairs(a, k);
    return 0;
}
