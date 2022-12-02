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
    vector<vector<pair<int, ll>>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<ll> x(n);
    function<void(int, int, ll)> dfs = [&](int u, int f, ll val) {
        x[u] = val;
        for (const auto& [v, w] : g[u]) {
            if (v == f) {
                continue;
            }
            dfs(v, u, val ^ w);
        }
    };
    dfs(0, -1, 0);
    vector<ll> cnt(64);
    for (int i = 0; i < n; ++i) {
        ll mask = 1;
        for (int j = 0; j < 63; ++j) {
            if (mask & x[i]) {
                ++cnt[j];
            }
            mask *= 2;
        }
    }
    ll ans = 0, mod = 1e9 + 7, mask = 1;
    for (int j = 0; j < 63; ++j) {
        ans = (ans + (mask % mod) * ((cnt[j] * ((ll)n - cnt[j])) % mod)) % mod;
        mask *= 2;
    }
    cout << ans << endl;
    return 0;
}
