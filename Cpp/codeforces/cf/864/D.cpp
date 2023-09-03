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
    vector<ll> imp(n);
    for (int i = 0; i < n; ++i) {
        cin >> imp[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> sz(n), pa(n, -1);
    function<void(int, int)> dfs = [&](int u, int f) {
        sz[u] = 1;
        pa[u] = f;
        for (const auto& v : g[u]) {
            if (v == f) {
                continue;
            }
            dfs(v, u);
            imp[u] += imp[v];
            sz[u] += sz[v];
        }
    };
    dfs(0, -1);
    vector<set<pair<int, int>>> vec(n);
    for (int u = 0; u < n; ++u) {
        for (const auto& v : g[u]) {
            if (v == pa[u]) {
                continue;
            }
            vec[u].emplace(sz[v], -v);
        }
    }
    while (m--) {
        int op, x;
        cin >> op >> x;
        --x;
        if (op == 1) {
            cout << imp[x] << '\n';
            continue;
        }
        if (vec[x].empty()) {
            continue;
        }
        auto [szs, v] = *vec[x].rbegin();
        int sonx = -v;
        ll tmpimp = imp[x];
        imp[x] -= imp[sonx];
        imp[sonx] = tmpimp;
        int tmpsz = sz[x];
        sz[x] -= sz[sonx];
        sz[sonx] = tmpsz;
        vec[x].erase(prev(vec[x].end()));
        vec[sonx].emplace(sz[x], -x);
        vec[pa[x]].erase(make_pair(tmpsz, -x));
        vec[pa[x]].emplace(sz[sonx], -sonx);
        pa[sonx] = pa[x];
        pa[x] = sonx;
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
