#include "usual.h"

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int n = tires.size();
        vector<int> cost(21, 1e7);
        vector<vector<long long>> times(n, vector<long long>(21, 1));
        for (int i = 0; i < n; ++i) {
            times[i][1] = tires[i][0];
            cost[1] = min(cost[1], (int)times[i][1]);
            long long t = tires[i][0];
            for (int j = 2; j <= 20; ++j) {
                t = min((long long)1e7, t * tires[i][1]);
                times[i][j] = min((long long)1e7, times[i][j - 1] + t);
                cost[j] = min(cost[j], (int)times[i][j]);
            }
        }
        vector<int> dp(numLaps + 1, 1e9);
        dp[0] = -changeTime;
        for (int i = 1; i <= numLaps; ++i) {
            for (int j = i - 1; j >= max(0, i - 20); --j) {
                dp[i] = min(dp[i], dp[j] + cost[i - j] + changeTime);
            }
            // cout << i << " " << dp[i] << endl;
        }
        return dp[numLaps];
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> t{{99, 7}};
    int a = 85, b = 95;
    Solution().minimumFinishTime(t, a, b);
    return 0;
}
