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
    int n, q;
    cin >> n >> q;
    vector<ll> pre(n + 1);
    ll ans = 0, mod = 998244353, k = 1;
    pre[1] = 1;
    for (int i = 2; i <= n; ++i) {
        k = (k * 10) % mod;
        pre[i] = (pre[i - 1] + k) % mod;
    }
    ans = pre[n];
    multiset<tuple<ll, ll, ll>> s;
    s.emplace(1, n, 1);
    while (q--) {
        ll l, r, d;
        cin >> l >> r >> d;
        l = n + 1 - l;
        r = n + 1 - r;
        swap(l, r);
        auto p = s.lower_bound(make_tuple(l, -1, -1));
        if (p != s.begin()) {
            auto q = prev(p);
            if (q != s.end()) {
                auto [l1, r1, d1] = *q;
                if (l <= r1 && r1 <= r) {
                    s.erase(q);
                    ans = ((ans - d1 * (pre[r1] - pre[l - 1]) % mod) % mod + mod) % mod;
                    s.emplace(l1, l - 1, d1);
                } else if (r < r1) {
                    s.erase(q);
                    ans = ((ans - d1 * (pre[r] - pre[l - 1]) % mod) % mod + mod) % mod;
                    s.emplace(l1, l - 1, d1);
                    s.emplace(r + 1, r1, d1);
                }
            }
        }
        while (p != s.end() && get<1>(*p) <= r) {
            auto q = next(p);
            auto [l1, r1, d1] = *p;
            s.erase(p);
            ans = ((ans - d1 * (pre[r1] - pre[l1 - 1]) % mod) % mod + mod) % mod;
            p = q;
        }
        if (p != s.end() && get<0>(*p) <= r) {
            auto [l1, r1, d1] = *p;
            s.erase(p);
            s.emplace(r + 1, r1, d1);
            ans = ((ans - d1 * (pre[r] - pre[l1 - 1]) % mod) % mod + mod) % mod;
        }
        s.emplace(l, r, d);
        ans = (ans + d * ((pre[r] - pre[l - 1]) % mod + mod) % mod) % mod;
        cout << ans << endl;
    }
    return 0;
}
