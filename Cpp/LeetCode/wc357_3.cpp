#include "usual.h"

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> d(n, vector<int>(n, -1));
        vector<pair<int, int>> dirs{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        auto bfs = [&]() {
            queue<pair<int, int>> q;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1) {
                        d[i][j] = 0;
                        q.emplace(i, j);
                    }
                }
            }
            int step = 0;
            while (!q.empty()) {
                int l = q.size();
                while (l--) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (const auto& [dx, dy] : dirs) {
                        int u = x + dx, v = y + dy;
                        if (0 <= u && u < n && 0 <= v && v < n && d[u][v] == -1) {
                            d[u][v] = step + 1;
                            q.emplace(u, v);
                        }
                    }
                }
                ++step;
            }
        };
        bfs();
        vector<vector<int>> dis(n, vector<int>(n, 0));
        priority_queue<tuple<int, int, int>> q;
        dis[0][0] = d[0][0];
        q.emplace(d[0][0], 0, 0);
        while (!q.empty()) {
            auto [d0, x, y] = q.top();
            q.pop();
            for (const auto& [dx, dy] : dirs) {
                int u = x + dx, v = y + dy;
                if (0 <= u && u < n && 0 <= v && v < n) {
                    int d1 = min(d0, d[u][v]);
                    if (d1 > dis[u][v]) {
                        dis[u][v] = d1;
                        q.emplace(d1, u, v);
                    }
                }
            }
        }
        return dis[n - 1][n - 1];
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> d{{0,0,1},{0,0,0},{0,0,0}};
    Solution().maximumSafenessFactor(d);
    return 0;
}
