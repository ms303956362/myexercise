#include "usual.h"

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        // vector<vector<int>> sum(n, vector<int>(n));
        // for (int i = 0; i < n; ++i) {
        //     sum[i][i] = nums[i];
        //     for (int j = i + 1; j < n; ++j) {
        //         sum[i][j] = sum[i][j - 1] +nums[j];
        //     }
        // }
        // vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));
        // for (int i = n - 1; i >= 0; --i) {
        //     dp[i][i] = true;
        //     dp[i][i + 1] = true;
        //     for (int j = i + 2; j < n; ++j) {
        //         for (int k = i; k < j; ++k) {
        //             if ((i == k || sum[i][k] >= m) && (k + 1 == j || sum[k + 1][j] >= m) && dp[i][k] && dp[k + 1][j]) {
        //                 dp[i][j] = true;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return dp[0][n - 1];
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] + nums[i + 1] >= m) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{2, 2, 1};
    int m = 4;
    Solution().canSplitArray(v, m);
    return 0;
}
