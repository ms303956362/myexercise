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
    ll n, k;
    cin >> n >> k;
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<ll> d2(n);
    ll a = 0, d = 0, ans = 0;
    for (ll i = n - 1; i >= 0; --i) {
        d += d2[i];
        a += d;
        if (a < b[i]) {
            ll k2 = min(i + 1, k), t = (b[i] - a + k2 - 1) / k2;
            a += t * k2;
            ans += t;
            if (i > 0) {
                d2[i - 1] -= t;
                if (i - k - 1 >= 0) {
                    d2[i - k - 1] += t;
                }
            }
        }
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
