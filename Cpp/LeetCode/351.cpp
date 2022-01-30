#include "usual.h"

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<vector<int>>> nums(10, vector<vector<int>>(10));
        vector<vector<int>> masks(10, vector<int>(10));
        nums[1][3] = {2};
        // nums[1][6] = {2, 5};
        nums[1][7] = {4};
        // nums[1][8] = {4, 5};
        nums[1][9] = {5};
        // nums[2][7] = {4, 5};
        nums[2][8] = {5};
        // nums[2][9] = {5, 6};
        // nums[3][4] = {2, 5};
        nums[3][7] = {5};
        // nums[3][8] = {5, 6};
        nums[3][9] = {6};
        nums[4][6] = {5};
        // nums[4][9] = {5, 8};
        // nums[6][7] = {5, 8};
        nums[7][9] = {8};
        for (int i = 1; i <= 9; ++i) {
            for (int j = i + 1; j <= 9; ++j) {
                for (const auto& k : nums[i][j]) {
                    masks[i][j] |= (1 << k);
                }
                masks[j][i] = masks[i][j];
            }
        }
        vector<vector<unordered_map<int, int>>> dp(10, vector<unordered_map<int, int>>(10));
        dp[0][0][0] = 1;
        for (int i = 1; i <= 9; ++i) {
            dp[1][i][1 << i] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (int k = 1; k <= 9; ++k) {  // 枚举第i-1个数字k
                for (const auto& [s, cnt] : dp[i - 1][k]) {
                    for (int j = 1; j <= 9; ++j) { // 新加入的第i个数字为j
                        if ((s & (1 << j)) == 0) {      // s中不包括j
                            if ((masks[k][j] & s) == masks[k][j]) {     // 从k连到j，经过的数字在s中都出现了
                                dp[i][j][s | (1 << j)] += cnt;
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = m; i <= n; ++i) {
            for (int j = 1; j <= 9; ++j) {
                for (const auto& [s, cnt] : dp[i][j]) {
                    ans += cnt;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution().numberOfPatterns(1, 2);
    return 0;
}
