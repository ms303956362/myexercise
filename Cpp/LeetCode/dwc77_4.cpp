#include "usual.h"

class Solution {
    const int NOTVST = 0, VST = 1, FIRE = 2;

public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int l = 0, h = 1e9;
        while (l <= h) {
            int m = (l + h) / 2;
            if (check(m, grid)) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return h;
    }

    bool check(int initial_time, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> vst(m, vector<int>(n));
        queue<pair<int, int>> q1, q2;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q1.emplace(i, j);
                    vst[i][j] = FIRE;
                }
            }
        }
        for (int t = 0; t < initial_time && !q1.empty(); ++t) {
            int l = q1.size();
            for (int k = 0; k < l; ++k) {
                auto [x, y] = q1.front();
                q1.pop();
                for (const auto& [dx, dy] : dirs) {
                    int u = x + dx, v = y + dy;
                    if (0 <= u && u < m && 0 <= v && v < n && grid[u][v] != 2 && vst[u][v] != FIRE) {
                        vst[u][v] = FIRE;
                        q1.emplace(u, v);
                    }
                }
            }
        }
        q2.emplace(0, 0);
        vst[0][0] = VST;
        while (!q2.empty()) {
            int l = q1.size();
            bool fire_final = false;
            for (int k = 0; k < l; ++k) {
                auto [x, y] = q1.front();
                q1.pop();
                for (const auto& [dx, dy] : dirs) {
                    int u = x + dx, v = y + dy;
                    if (0 <= u && u < m && 0 <= v && v < n && grid[u][v] != 2 && vst[u][v] != FIRE) {
                        if (u == m - 1 && v == n - 1) {
                            fire_final = true;
                        }
                        vst[u][v] = FIRE;
                        q1.emplace(u, v);
                    }
                }
            }
            l = q2.size();
            for (int k = 0; k < l; ++k) {
                auto [x, y] = q2.front();
                q2.pop();
                if (x == m - 1 && y == n - 1) {
                    return true;
                }
                for (const auto& [dx, dy] : dirs) {
                    int u = x + dx, v = y + dy;
                    if (0 <= u && u < m && 0 <= v && v < n && grid[u][v] != 2 && (vst[u][v] == NOTVST || u == m - 1 && v == n - 1 && fire_final)) {
                        vst[u][v] = VST;
                        q2.emplace(u, v);
                    }
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid{{ 0, 2, 0, 0, 1 }, { 0, 2, 0, 2, 2 }, { 0, 2, 0, 0, 0 }, { 0, 0, 2, 2, 0 }, { 0, 0, 0, 0, 0 }};
    Solution().maximumMinutes(grid);
    return 0;
}
