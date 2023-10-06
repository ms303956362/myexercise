#include "usual.h"

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long total = 0;
        int n = nums.size();
        for (const auto& num : nums) {
            total += num;
        }
        int ans = 0;
        while (target > total) {
            ans += n;
            target -= total;
        }
        int extra = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i) {
            nums.push_back(nums[i]);
        }
        int i = 0, j = 0;
        long long sum = 0;
        while (i < 2 * n) {
            sum += nums[i];
            while (j < i && sum > target) {
                sum -= nums[j];
                ++j;
            }
            if (sum == target) {
                extra = min(extra, i - j + 1);
            }
            ++i;
        }
        return extra >= 0x3f3f3f3f ? -1 : (ans + extra);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
