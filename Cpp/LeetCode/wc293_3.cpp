#include "usual.h"

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        vector<vector<int>> dp(n + 1, vector<int>(32));
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1];
            for (int j = 0; j < 32; ++j) {
                if (candidates[i] & (1 << j)) {
                    ++dp[i][j];
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < 32; ++j) {
            ans = max(ans, dp[0][j]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
