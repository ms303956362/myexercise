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
    string s;
    cin >> s;
    ll ans = 0, n = s.size();
    ll i = 0;
    if (s == string(n, '1')) {
        cout << n * n << '\n';
        return;
    }
    while (i < n) {
        while (i < n && s[i] == '0') {
            ++i;
        }
        if (i < n) {
            ll len  = 0;
            while (i < n && s[i] == '1') {
                ++i;
                ++len;
            }
            for (ll t = max((len + 1) / 2 - 3, 0LL); t <= min((len + 1) / 2 + 3, len); ++t) {
                ans = max(ans, t * (len - t + 1));
            }
        }
    }
    // cout << ans << '\n';
    ll pre = 0, suf = 0;
    i = 0;
    while (i < n && s[i] == '1') {
        ++pre;
        ++i;
    }
    i = n - 1;
    while (i >= 0 && s[i] == '1') {
        --i;
        ++suf;
    }
    ll len = pre + suf;
    for (ll i = suf; i >= 0; --i) {
        ans = max(ans, len * (suf - i + 1));
        --len;
    }
    len = pre + suf - 1;
    for (ll i = suf + 1; i < n; ++i) {
        ans = max(ans, len * (i - suf + 1));
        --len;
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
