#include "usual.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int ,pair<int, int>>> dp(n);
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            int f = 0, s = 0;
            for (int j = 0; j < i; ++j) {
                int d = nums[i] - nums[j];
                if (!dp[i].count(d))
                    dp[i][d] = {0, 0};
                if (dp[j].count(d))
                    dp[i][d].first += dp[j][d].first + dp[j][d].second;
                ++dp[i][d].second;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> v{7, 7, 7, 7, 7};
    Solution().numberOfArithmeticSlices(v);
    return 0;
}
