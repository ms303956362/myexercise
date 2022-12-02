#include "usual.h"

class Solution {
public:
    int lakeCount(vector<string>& field) {
        int m = field.size(), n = field[0].size();
        vector<vector<bool>> vst(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        auto bfs = [&](int i, int j) {
            queue<pair<int, int>> q;
            vst[i][j] = true;
            q.emplace(i, j);
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (const auto& [dx, dy] : dirs) {
                    int u = x + dx, v = y + dy;
                    if (0 <= u && u < m && 0 <= v && v < n && !vst[u][v] && field[u][v] == 'W') {
                        vst[u][v] = true;
                        q.emplace(u, v);
                    }
                }
            }
        };
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (field[i][j] == 'W' && !vst[i][j]) {
                    bfs(i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
