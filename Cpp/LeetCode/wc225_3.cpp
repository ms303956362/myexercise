#include "usual.h"

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> a;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = (dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ matrix[i - 1][j - 1]);
                a.push_back(dp[i][j]);
            }
        }
        sort(a.begin(), a.end());
        return a[n * m - k];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
