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
const ll mod = 1e9 + 7;

ll pow(ll x, ll n, ll mod) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = (ret * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n), sz(n, 1);
    iota(p.begin(), p.end(), 0);
    function<int(int)> find = [&](int u) {
        return p[u] == u ? u : (p[u] = find(p[u]));
    };
    auto merge = [&](int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) {
            return false;
        }
        p[pu] = pv;
        sz[pv] += sz[pu];
        return true;
    };
    for (int i = 0; i < n - 1; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        --u;
        --v;
        if (x == 0) {
            merge(u, v);
        }
    }
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        if (i == find(i)) {
            a.push_back(sz[i]);
        }
    }
    ll ans = pow(n, k, mod);
    for (const auto& l : a) {
        ans = (ans - pow(l, k, mod) + mod) % mod;
    }
    cout << ans << '\n';
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
