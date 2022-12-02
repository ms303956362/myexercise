#include "usual.h"

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        vector<vector<int>> dis(m, vector<int>(n, 0x3f3f3f3f));
        vector<pair<int, int>> dir{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        q.emplace(0, 0, 0);
        dis[0][0] = 0;
        while (!q.empty()) {
            auto [d, x, y] = q.top();
            q.pop();
            if (d > dis[x][y]) {
                continue;
            }
            for (const auto& [dx, dy] : dir) {
                int u = x + dx, v = y + dy;
                if (0 <= u && u < m && 0 <= v && v < n && dis[u][v] > (d + grid[u][v])) {
                    dis[u][v] = d + grid[u][v];
                    q.emplace(dis[u][v], u, v);
                }
            }
        }
        return dis[m - 1][n - 1];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
