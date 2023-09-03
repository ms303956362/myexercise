#include "usual.h"

class Solution {
public:
    int challengeOfTheKeeper(vector<string>& maze) {
        const int INF = 0x3f3f3f3f;
        int m = maze.size(), n = maze[0].size();
        int xs, ys, xt, yt;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (maze[i][j] == 'S') {
                    xs = i;
                    ys = j;
                } else if (maze[i][j] == 'T') {
                    xt = i;
                    yt = j;
                }
            }
        }
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> dis(m, vector<int>(n, INF));
        queue<pair<int, int>> q;
        q.emplace(xt, yt);
        dis[xt][yt] = 0;
        int step = 1;
        while (!q.empty()) {
            int l = q.size();
            while (l--) {
                auto [x, y] = q.front();
                q.pop();
                for (const auto& [dx, dy] : dirs) {
                    int u = x + dx, v = y + dy;
                    if (0 <= u && u < m && 0 <= v && v < n && maze[u][v] != '#' && dis[u][v] == INF) {
                        dis[u][v] = step;
                        q.emplace(u, v);
                    }
                }
            }
            ++step;
        }
        vector<vector<int>> f(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (maze[i][j] != '.') {
                    continue;
                }
                int f1 = (maze[m - 1- i][j] == '#' ? 0 : dis[m - 1 - i][j]), f2 = (maze[i][n - 1 - j] == '#' ? 0 : dis[i][n - 1 - j]);
                f[i][j] = max(f1, f2);
            }
        }
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // function<void(int, int)> dfs = [&](int x, int y) {
        //     if (dp[x][y] != -1) {
        //         return;
        //     }
        //     if (x == xt && y == yt) {
        //         dp[x][y] = 0;
        //         return;
        //     }
        //     dp[x][y] = INF;
        //     int f_min = INF;
        //     for (const auto& [dx, dy] : dirs) {
        //         int u = x + dx, v = y + dy;
        //         if (0 <= u && u < m && 0 <= v && v < n && maze[u][v] != '#') {
        //             dfs(u, v);
        //             f_min = min(f_min, dp[u][v]);
        //         }
        //     }
        //     dp[x][y] = max(f[x][y], f_min);
        // };
        // dfs(xs, ys);
        // return dp[xs][ys] >= INF ? -1 : dp[xs][ys];
        vector<vector<int>> dp(m, vector<int>(n, INF));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q2;
        q2.emplace(f[xs][ys], xs, ys);
        dp[xs][ys] = f[xs][ys];
        while (!q2.empty()) {
            auto [d, x, y] = q2.top();
            q2.pop();
            if (d > dp[x][y]) {
                continue;
            }
            for (const auto& [dx, dy] : dirs) {
                int u = x + dx, v = y + dy;
                if (0 <= u && u < m && 0 <= v && v < n && maze[u][v] != '#' && max(d, f[u][v]) < dp[u][v]) {
                    dp[u][v] = max(d, f[u][v]);
                    q2.emplace(dp[u][v], u, v);
                }
            }
        }
        return dp[xt][yt] >= INF ? -1 : dp[xt][yt];
    }
};

int main(int argc, char const *argv[])
{
    vector<string> v{"........T.","..........","....#..#..","........#.","..#......#","#...#.....",".........#",".#S.......","#.........","..##.#..#."};
    // vector<string> v{".....","##S..","...#.","T.#..","###.."};
    cout << Solution().challengeOfTheKeeper(v) << endl;
    return 0;
}

/*
........T.
..........
....#..#..
........#.
..#......#
#...#.....
.........#
.#S.......
#.........
..##.#..#.

*/