#include "usual.h"

class Solution {
public:
    int flipChess(vector<string>& chessboard) {
        int n = chessboard.size(), m = chessboard[0].size();
        vector<pair<int, int>> dxdy{{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) { // 遍历放黑棋的位置
                if (chessboard[i][j] != '.')
                    continue;
                vector<string> a(chessboard);
                a[i][j] = 'X';
                int curr = 0;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                while (!q.empty()) { // 遍历起始点
                    int ii = q.front().first, jj = q.front().second;
                    q.pop();
                    for (const auto& [dx, dy] : dxdy) { // 遍历8个方向
                        bool ok = false;
                        vector<pair<int, int>> path;
                        for (int x = ii + dx, y = jj + dy; 0 <= x && x < n && 0 <= y && y < m; x += dx, y += dy) { // 沿该方向走
                            if (a[x][y] == 'X') {
                                ok = true;
                                break;
                            } else if (a[x][y] == '.')
                                break;
                            path.emplace_back(x, y);
                        }
                        if (ok) {
                            curr += path.size();
                            for (const auto& [x, y] : path) {
                                q.emplace(x, y);
                                a[x][y] = 'X';
                            }
                        }
                    }
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
