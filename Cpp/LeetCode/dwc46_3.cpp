#include "usual.h"

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        vector<vector<bool>> vst(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j)
                if (isWater[i][j]) {
                    q.push({i, j});
                    vst[i][j] = true;
                }
        }
        int level = 1;
        vector<pair<int, int>> dxdy{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int l = q.size();
            for (int k = 0; k != l; ++k) {
                auto [i, j] = q.front();
                q.pop();
                for (const auto&[dx, dy] : dxdy) {
                    int x = i + dx, y = j + dy;
                    if (0 <= x && x < n && 0 <= y && y < m && !vst[x][y]) {
                        ans[x][y] = level;
                        vst[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
            ++level;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
