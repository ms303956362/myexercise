#include "usual.h"

class Solution {
    using ll = long long;
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<ll>> dp(m, vector<ll>(n));
        ll mod = 1e9 + 7;
        vector<tuple<int, int, int>> v;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                v.emplace_back(-grid[i][j], i, j);
            }
        }
        sort(v.begin(), v.end());
        vector<pair<int, int>> dirs{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        for (const auto& [g, i, j] : v) {
            dp[i][j] = 1;
            for (const auto& [dx, dy] : dirs) {
                int x = i + dx, y = j + dy;
                if (0 <= x && x < m && 0 <= y && y < n && grid[x][y] > grid[i][j]) {
                    dp[i][j] = (dp[i][j] + dp[x][y]) % mod;
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = (ans + dp[i][j]) % mod;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
