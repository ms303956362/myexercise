#include "usual.h"

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n + 1);
        dp[n] = true;
        if (nums[n - 2] == nums[n - 1]) {
            dp[n - 2] = true;
        }
        for (int i = n - 3; i >= 0; --i) {
            dp[i] = (nums[i] == nums[i + 1] && dp[i + 2] || nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2] && dp[i + 3] || nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2] && dp[i + 3]);
        }
        return dp[0];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
