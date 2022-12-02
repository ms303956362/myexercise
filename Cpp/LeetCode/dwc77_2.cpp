#include "usual.h"

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long total = 0;
        for (const auto& num : nums) {
            total += num;
        }
        long long sum = 0, n = nums.size(), ans = 0, min_diff = INT_MAX;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int pre = sum / (i + 1), post = ((i == n - 1) ? 0 : (total - sum) / (n - i - 1));
            if (abs(pre - post) < min_diff) {
                min_diff = abs(pre - post);
                ans = i;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
