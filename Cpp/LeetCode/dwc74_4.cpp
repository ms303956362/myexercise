#include "usual.h"

class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size(), cnt = 0, k1 = n, k2 = n;
        set<int> idx;
        vector<vector<int>> dp(n + 1, vector<int>(numCarpets + 1));
        for (int i = n - 1; i >= 0; --i) {
            if (floor[i] == '0') {
                dp[i] = dp[i + 1];
                continue;
            }
            idx.insert(i);
            ++cnt;
            dp[i][0] = cnt;
            for (int j = 1; j <= numCarpets; ++j) {
                dp[i][j] = dp[k1][j] + 1;
                auto p = idx.lower_bound(i + carpetLen);
                if (p == idx.end()) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min(dp[i][j], dp[*p][j - 1]);
                }
            }
            k1 = i;
        }
        return dp[0][numCarpets];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
