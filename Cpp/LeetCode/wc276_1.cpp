#include "usual.h"

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        // unordered_map<int, unordered_map<int, int>> dp;
        // function<void(int, int)> dfs = [&](int i, int t)
        // {
        //     if (dp.count(i) && dp[i].count(t))
        //     {
        //         return;
        //     }
        //     if (t == 0 || i >= target)
        //     {
        //         dp[i][t] = target - i;
        //         return;
        //     }
        //     dfs(i + 1, t);
        //     dfs(2 * i, t - 1);
        //     dp[i][t] = -1;
        //     if (dp[i + 1][t] >= 0 && dp[2 * i][t - 1] >= 0)
        //     {
        //         dp[i][t] = min(dp[i + 1][t], dp[2 * i][t - 1]) + 1;
        //     }
        //     else if (dp[i + 1][t] >= 0)
        //     {
        //         dp[i][t] = dp[i + 1][t] + 1;
        //     }
        //     else if (dp[2 * i][t - 1] >= 0)
        //     {
        //         dp[i][t] = dp[2 * i][t - 1] + 1;
        //     }
        // };
        // dfs(1, maxDoubles);
        // return dp[1][maxDoubles];
        int ans = 0;
        while (target > 1) {
            while (target % 2 == 0 && maxDoubles  > 0) {
                ++ans;
                target /= 2;
                --maxDoubles;
            }
            if (maxDoubles == 0) {
                ans += target - 1;
                break;
            }
            while (target % 2 == 1) {
                --target;
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
