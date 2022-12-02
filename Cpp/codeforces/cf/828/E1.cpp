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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    bool ok = false;
    for (ll x = a + 1; x <= c; ++x) {
        ll g = __gcd(x, a * b);
        ll e = a * b / g;
        for (ll k = b / e; k <= d / e; ++k) {
            if (b < k * e && k * e <= d) {
                cout << x << " " << k * e << endl;
                ok = true;
                break;
            }
        }
        if (ok) {
            break;
        }
    }
    if (!ok) {
        cout << -1 << " " << -1 << endl;
    }
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
