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
#include <numeric>
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
    vector<string> grid(m, string(n, 'a'));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<char> nxt(256);
    nxt['s'] = 'n';
    nxt['n'] = 'u';
    nxt['u'] = 'k';
    nxt['k'] = 'e';
    nxt['e'] = 's';
    vector<vector<bool>> vst(m, vector<bool>(n));
    vector<pair<int, int>> dir{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    function<bool(int, int)> dfs = [&](int x, int y) {
        vst[x][y] = true;
        if (x == m - 1 && y == n - 1) {
            return true;
        }
        for (const auto& [dx, dy] : dir) {
            int u = x + dx, v = y + dy;
            if (0 <= u && u < m && 0 <= v && v < n && !vst[u][v] && grid[u][v] == nxt[grid[x][y]] && dfs(u, v)) {
                return true;
            }
        }
        return false;
    };
    cout << ((grid[0][0] == 's' && dfs(0, 0)) ? "Yes" : "No") << '\n';
    return 0;
}
