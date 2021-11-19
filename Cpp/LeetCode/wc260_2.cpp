#include "usual.h"

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long ans = 0x3f3f3f3f3f3f;
        int n = grid[0].size();
        vector<long long> pre1(n + 1), pre2(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre1[i] = pre1[i - 1] + grid[0][i - 1];
            pre2[i] = pre2[i - 1] + grid[1][i - 1];
        }
        for (int i = 1; i <= n; ++i) {
            long long s1 = pre1[n] - pre1[i], s2 = pre2[i - 1];
            if (s1 > s2)
                ans = min(ans, s1);
            else
                ans = min(ans, s2);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
