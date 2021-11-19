#include "usual.h"

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m = rides.size();
        sort(rides.begin(), rides.end());
        vector<long long> dp(m + 1), st;
        for (const auto& r : rides) {
            st.push_back(r[0]);
        }
        for (int i = m - 1; i >= 0; --i) {
            int j = lower_bound(st.begin() + i + 1, st.end(), (long long)rides[i][1]) - st.begin();
            dp[i] = max(dp[i + 1], (long long)rides[i][1] - (long long)rides[i][0] + (long long)rides[i][2] + dp[j]);
        }
        return dp[0];
    }
};

int main(int argc, char const *argv[])
{
    int n = 5;
    vector<vector<int>> a{{2, 5, 4}, {1, 5, 1}};
    Solution().maxTaxiEarnings(n, a);
    return 0;
}
