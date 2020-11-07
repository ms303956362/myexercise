#include "usual.h"

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> a(n, vector <int>(n, 0));
        vector<int> cnt(n, 0);
        for (const auto& r : roads) {
            ++a[r[0]][r[1]];
            ++a[r[1]][r[0]];
            ++cnt[r[0]];
            ++cnt[r[1]];
        }
        int ans = 0;
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != n; ++j) {
                if (j == i)
                    continue;
                ans = max(ans, cnt[i] + cnt[j] - a[i][j]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
