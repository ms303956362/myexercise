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
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<bool>> vst(n, vector<bool>(n));
    queue<pair<int, int>> q;
    vst[0][n - 1] = true;
    q.emplace(0, n - 1);
    int step = 0;
    while (!q.empty()) {
        int l = q.size();
        for (int i = 0; i < l; ++i) {
            auto [x, y] = q.front();
            q.pop();
            if (x == n - 1 && y == 0) {
                cout << step << '\n';
                return;
            }
            for (const auto& u : g[x]) {
                for (const auto& v : g[y]) {
                    if (c[u] != c[v] && !vst[u][v]) {
                        vst[u][v] = true;
                        q.emplace(u, v);
                    }
                }
            }
        }
        ++step;
    }
    cout << -1 << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
