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

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v, dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    unordered_map<int, unordered_set<int>> points;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points[x].insert(y);
        v.emplace_back(x, y);
    }
    unordered_map<int, unordered_map<int, tuple<int, int, int>>> dp;
    function<void(int, int)> dfs = [&](int x, int y) {
        if (dp.count(x) && dp[x].count(y)) {
            return;
        }
        dp[x][y] = make_tuple(0x3f3f3f3f, 0, 0);
        for (const auto& [dx, dy] : dirs) {
            int u = x + dx, v = y + dy;
            if (!points.count(u) || !points[u].count(v)) {
                dp[x][y] = make_tuple(1, u, v);
                return;
            }
            dfs(u, v);
            int d = get<0>(dp[u][v]), dxy = get<0>(dp[x][y]);
            if (d + 1 < dxy) {
                int a = get<1>(dp[u][v]), b = get<2>(dp[u][v]);
                dp[x][y] = make_tuple(d + 1, a, b);
            }
        }
    };
    for (const auto& [x, y] : v) {
        if (!dp.count(x) || !dp[x].count(y)) {
            dfs(x, y);
        }
        cout << get<1>(dp[x][y]) << " " << get<2>(dp[x][y]) << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
