#include "usual.h"

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // vector<vector<int>> g(m * n);
        // priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         for (const auto& [di, dj] : dirs) {
        //             int x = i + di, y = j + dj;
        //             if (0 <= x && x < m && 0 <= y && y < n) {
        //                 q.emplace(grid[x][y], i * n * j, x * n + y);
        //             }
        //         }
        //     }
        // }
        vector<vector<int>> dis(m, vector<int>(n, 0x3f3f3f3f));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        q.emplace(0, 0, 0);
        bool ok = false;
        for (const auto& [dx, dy] : dirs) {
            int u = dx, v = dy;
            if (0 <= u && u < m && 0 <= v && v < n && grid[u][v] <= 1) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            return -1;
        }
        while (!q.empty()) {
            auto [t, x, y] = q.top();
            q.pop();
            if (t > dis[x][y]) {
                continue;
            }
            if (x == m - 1 && y == n - 1) {
                return t;
            }
            for (const auto& [dx, dy] : dirs) {
                int u = x + dx, v = y + dy;
                if (0 <= u && u < m && 0 <= v && v < n) {
                    int d = max(t + 1, grid[u][v]);
                    if (grid[u][v] > t && (grid[u][v] - t) % 2 == 0) {
                        ++d;
                    }
                    if (d < dis[u][v]) {
                        dis[u][v] = d;
                        q.emplace(d, u, v);
                    }
                }
            }
        }
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << dis[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dis[m - 1][n - 1] >= 0x3f3f3f3f ? -1 : dis[m - 1][n - 1];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
