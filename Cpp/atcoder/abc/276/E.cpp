// IO
#include <iostream>
#include <iomanip>      // std::setprecision
#include <sstream>
// ordered container
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <stack>
#include <queue>
// associative-container
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
// algorithm
#include <algorithm>
#include <cmath>
// utility
#include <initializer_list>
#include <iterator>
#include <memory>
#include <utility>
// c
#include <cstdio>
#include <cstdlib>
#include <cstring>
// functional
#include <functional>

using namespace std;

using ll = long long;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    int sx = 0, sy = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            grid[i][j] = c;
            if (c == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    vector<pair<int, int>> dirs{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int ans = -1;
    vector<vector<bool>> vst(m, vector<bool>(n, false));
    function<void(int, int, int)> dfs = [&](int x, int y, int len) {
        vst[x][y] = true;
        for (const auto& [dx, dy] : dirs) {
            int u = x + dx, v = y + dy;
            if (0 <= u && u < m && 0 <= v && v < n && grid[u][v] != '#') {
                if (grid[u][v] == 'S') {
                    ans = max(ans, len);
                }
                if (!vst[u][v]) {
                    dfs(u, v, len + 1);
                }
            }
        }
    };
    dfs(sx, sy, 1);
    cout << (ans >= 4 ? "Yes" : "No") << endl;
    return 0;
}
