#include "usual.h"

class Solution {
public:
    int maxSum(vector<int>& nums) {
        auto max_digit = [](int num) {
            int d = 0;
            while (num > 0) {
                d = max(d, num % 10);
                num /= 10;
            }
            return d;
        };
        int n = nums.size();
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (max_digit(nums[i]) == max_digit(nums[j]) && nums[i] + nums[j] > ans) {
                    ans = nums[i] + nums[j];
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
