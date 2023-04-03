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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> start(n + m + 1, -1), cnt(n + m + 1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        start[a[i]] = 0;
    }
    for (ll i = 1; i <= m; ++i) {
        ll p, v;
        cin >> p >> v;
        --p;
        cnt[a[p]] += i - start[a[p]];
        start[a[p]] = -1;
        start[v] = i;
        a[p] = v;
    }
    for (int i = 0; i <= n + m; ++i) {
        if (start[i] != -1) {
            cnt[i] += m + 1 - start[i];
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n + m; ++i) {
        if (cnt[i] > 0) {
            ll k = m + 1 - cnt[i];
            ans += m * (m + 1) / 2;
            if (k >= 2) {
                ans -= k * (k - 1) / 2;
            }
        }
    }
    cout << ans << '\n';
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
