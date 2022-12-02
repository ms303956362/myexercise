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
    int n, m;
    cin >> n >> m;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        q.emplace(w, u - 1, v - 1);
    }
    vector<pair<int, int>> qr;
    for (int i = 0; i < m; ++i) {
        int qi;
        cin >> qi;
        qr.emplace_back(qi, i);
    }
    sort(qr.begin(), qr.end());
    vector<int> p(n), sz(n, 1);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    ll ans = 0;
    function<int(int)> find = [&](int u) {
        return p[u] == u ? u : (p[u] = find(p[u]));
    };
    auto merge = [&](int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) {
            return false;
        }
        ans -= 1LL * sz[pu] * (sz[pu] - 1) / 2 + 1LL * sz[pv] * (sz[pv] - 1) / 2;
        p[pu] = pv;
        sz[pv] += sz[pu];
        ans += 1LL * sz[pv] * (sz[pv] - 1) / 2;
        return true;
    };
    vector<ll> res(m);
    for (int i = 0; i < m; ++i) {
        while (!q.empty() && get<0>(q.top()) <= qr[i].first) {
            auto [w, u, v] = q.top();
            q.pop();
            merge(u, v);
        }
        res[qr[i].second] = ans;
    }
    for (int i = 0; i < m; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
