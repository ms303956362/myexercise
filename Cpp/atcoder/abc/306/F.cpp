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

class BIT {
    ll n;
    vector<ll> tree;
public:
    BIT(ll _n) : n(_n + 1), tree(_n + 1, 0) {}
    BIT(const vector<ll>& a) : n(a.size() + 1), tree(a.size() + 1, 0) {
        for (ll i = 1; i < n; ++i) {
            update(i - 1, a[i - 1]);
        }
    }

    inline ll lowBit(ll i) { return i & (-i); }

    void update(ll i, ll delta) {
        ++i;
        while (i < n) {
            tree[i] += delta;
            i += lowBit(i);
        }
    }

    ll query(ll i) {
        ++i;
        ll sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= lowBit(i);
        }
        return sum;
    }

};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ll x;
            cin >> x;
            v.emplace_back(x, i);
        }
    }
    sort(v.begin(), v.end());
    vector<ll> cnt(n);
    BIT t(n);
    ll ans = 0;
    for (int k = 0; k < n * m; ++k) {
        auto [_, i] = v[k];
        ans += (n - i - 1) * (cnt[i] + 1) + t.query(n - 1) - t.query(i);
        t.update(i, 1);
        ++cnt[i];
    }
    cout << ans << '\n';
    return 0;
}
