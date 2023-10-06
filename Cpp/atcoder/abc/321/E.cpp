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

ll leftmost(ll x, ll d, ll n) {
    ll ret = x;
    while (d-- && ret <= n) {
        ret <<= 1;
    }
    return min(ret, n);
}

ll rightmost(ll x, ll d, ll n) {
    ll ret = x;
    while (d-- && ret <= n) {
        ret = (ret << 1) + 1;
    }
    return min(ret, n);
}

ll other_child(ll x, ll p) {
    if (x == (p << 1) + 1) { // right child
        return p << 1;
    }
    return (p << 1) + 1;
}

void solve() {
    ll n, x, k;
    cin >> n >> x >> k;
    if (k == 0) {
        cout << 1 << '\n';
        return;
    }
    ll ans = leftmost(x, k, n + 1) > n ? 0 : (rightmost(x, k, n) - leftmost(x, k, n) + 1);
    ll p = (x >> 1), d = 1;
    while (p >= 1 && k > d) {
        ll y = other_child(x, p);
        ans += leftmost(y, k - d - 1, n + 1) > n ? 0 : (rightmost(y, k - d - 1, n) - leftmost(y, k - d - 1, n) + 1);
        x = p;
        p >>= 1;
        ++d;
    }
    if (p >= 1) {
        ++ans;
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
