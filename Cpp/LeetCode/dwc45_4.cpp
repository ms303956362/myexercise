#include "usual.h"

class Solution {
    int ans;

public:
    int maxValue(vector<vector<int>>& events, int k) {
        int ans = 0;
        int n = events.size();
        sort(events.begin(), events.end());
        vector<int> starts(n);
        vector<vector<int>> dp(n, vector<int>(k, INT_MAX));
        for (int i = 0; i != n; ++i)
            starts[i] = events[i][0];
        for (int j = 0; j != k; ++j)
            dp[n - 1][j] = events[n - 1][2];
        for (int i = n - 2; i >= 0; --i) {
            dp[i][0] = max(dp[i + 1][0], events[i][2]);
            int i1 = upper_bound(starts.begin() + i, starts.end(), events[i][1]) - starts.begin();
            for (int j = 1; j != k; ++j) {
                dp[i][j] = max(dp[i + 1][j], (i1 == n ? 0 : dp[i1][j - 1]) + events[i][2]);
            }
        }
        return dp[0][k - 1];
    }

    // void dfs(int i, int cnt, int k, int sum, vector<vector<int>>& events) {
    //     if (cnt == k || events[i][2] >= events.rbegin()->at(0)) {
    //         ans = max(ans, sum);
    //         return;
    //     }
    // }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> s{{ 1, 2, 4 }, { 3, 4, 3 }, { 2, 3, 1 }};
    int k = 2;
    Solution().maxValue(s, k);
    return 0;
}
