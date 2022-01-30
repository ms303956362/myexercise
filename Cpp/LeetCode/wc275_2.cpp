#include "usual.h"

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = 0, n = nums.size();
        for (const auto& num : nums)
            k += num;
        if (k == n)
            return 0;
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        int ans = k - sum;
        for (int i = k; i < n + k; ++i) {
            sum -= nums[i - k];
            sum += nums[i % n];
            ans = min(ans, k - sum);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
