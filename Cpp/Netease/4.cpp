#include <iostream>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    int INF = 0x3f3f3f3f;
    vector<vector<int>> a(m, vector<int>(n)), dis(m, vector<int>(n, INF));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<pair<int, int>> dirs{{1, 0}, {0, -1}, {0, 1}};
    auto is_pos_valid = [&](int x, int y)
    {
        return 0 <= x && x < m && 0 <= y && y < n;
    };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    q.emplace(0, 0, 0);
    dis[0][0] = 0;
    while (!q.empty()) {
        auto [d, x, y] = q.top();
        q.pop();
        for (const auto& [dx, dy] : dirs) {
            int u = x + dx, v = y + dy;
            if (is_pos_valid(u, v)) {
                int step = (a[x][y] == a[u][v] ? 1 : 2);
                if (d + step < dis[u][v]) {
                    dis[u][v] = d + step;
                    q.emplace(d + step, u, v);
                }
            }
        }
    }
    cout << dis[m - 1][n - 1] << endl;
    return 0;
}

