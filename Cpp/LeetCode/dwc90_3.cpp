#include "usual.h"

class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int max_cnt = 0, ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ++dp[nums[i] % space];
            if (dp[nums[i] % space] >= max_cnt) {
                max_cnt = dp[nums[i] % space];
                ans = nums[i];
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
