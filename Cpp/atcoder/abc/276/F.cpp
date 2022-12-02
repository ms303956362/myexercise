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

    ll lowBit(ll i) { return i & (-i); }

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

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    BIT t1(2e5 + 5), t2(2e5 + 5);
    ll de = 0, nu = 0, mod = 998244353;
    unordered_map<ll, ll> cnt;
    for (ll k = 1; k <= n; ++k) {
        nu = k * k;
        ll num = a[k - 1];
        ll c = cnt[num], s = t1.query(num);
        de = (de + num * (2 * (c + 1) * (s + 1) - (c + 1) * (c + 1)) - num * (2 * c * s - c * c)) % mod;
        de = (de + 2 * (t2.query(2e5 + 2) - t2.query(num))) % mod;
        ++cnt[num];
        t1.update(num, 1);
        t2.update(num, num);
        cout << (de * pow(nu % mod, mod - 2, mod)) % mod << endl;
    }
    return 0;
}
