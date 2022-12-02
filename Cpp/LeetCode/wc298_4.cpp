#include "usual.h"

using ll = long long;
ll dp[205][205];
ll p[205][205];

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        memset(dp, -1, sizeof(ll) * 205 * 205);
        memset(p, 0, sizeof(ll) * 205 * 205);
        for (const auto& pr : prices) {
            p[pr[0]][pr[1]] = pr[2];
        }
        function<void(int, int)> dfs = [&](int h, int w)
        {
            if (dp[h][w] != -1)
            {
                return;
            }
            dp[h][w] = p[h][w];
            for (int h1 = 1; h1 < h; ++h1)
            {
                dfs(h1, w);
                dfs(h - h1, w);
                dp[h][w] = max(dp[h][w], dp[h1][w] + dp[h - h1][w]);
            }
            for (int w1 = 1; w1 < w; ++w1)
            {
                dfs(h, w1);
                dfs(h, w - w1);
                dp[h][w] = max(dp[h][w], dp[h][w1] + dp[h][w - w1]);
            }
        };
        dfs(m, n);
        return dp[m][n];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
