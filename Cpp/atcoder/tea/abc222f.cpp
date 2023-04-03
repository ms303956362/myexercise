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
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    vector<int> d(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].emplace_back(b - 1, c);
        g[b - 1].emplace_back(a - 1, c);
    }
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    vector<vector<pair<ll, int>>> dp1(n);
    vector<ll> cf(n);
    function<void(int, int)> dfs1 = [&](int u, int f) {
        for (const auto& [v, c] : g[u]) {
            if (v == f) {
                cf[u] = c;
                continue;
            }
            dfs1(v, u);
            if (dp1[v].empty() || dp1[v][0].first + c < d[v] + c) {
                dp1[u].emplace_back(d[v] + c, v);
            } else {
                dp1[u].emplace_back(dp1[v][0].first + c, v);
            }
        }
        sort(dp1[u].rbegin(), dp1[u].rend());
    };
    dfs1(0, -1);
    vector<vector<pair<ll, int>>> dp2(n);
    function<void(int, int)> dfs2 = [&](int u, int f) {
        if (!dp1[u].empty()) {
            dp2[u].push_back(dp1[u][0]);
            if (dp1[u].size() > 1) {
                dp2[u].push_back(dp1[u][1]);
            }
        }
        if (f >= 0) {
            dp2[u].emplace_back(d[f] + cf[u], f);
            if (!dp2[f].empty() && dp2[f][0].second != u) {
                dp2[u].emplace_back(dp2[f][0].first + cf[u], f);
            } else if (dp2[f].size() > 1 && dp2[f][1].second != u) {
                dp2[u].emplace_back(dp2[f][1].first + cf[u], f);
            }
        }
        sort(dp2[u].rbegin(), dp2[u].rend());
        for (const auto& [v, c] : g[u]) {
            if (v == f) {
                continue;
            }
            dfs2(v, u);
        }
    };
    dfs2(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << dp2[i][0].first << '\n';
    }
    return 0;
}
