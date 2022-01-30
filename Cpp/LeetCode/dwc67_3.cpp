#include "usual.h"

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;
                long long x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r1 * r1) {
                    g[i].push_back(j);
                }
            }
        }
        vector<bool> vst(n, false);
        function<int(int)> dfs = [&](int u)
        {
            vst[u] = true;
            int cnt = 1;
            for (const auto& v : g[u]) {
                if (!vst[v]) {
                    cnt += dfs(v);
                }
            }
            return cnt;
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            vst = vector<bool>(n, false);
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
