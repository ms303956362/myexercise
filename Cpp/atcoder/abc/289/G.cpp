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
    ll n, m;
    cin >> n >> m;
    vector<ll> c(m);
    map<ll, int> mp;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ++mp[x];
    }
    vector<int> b, cnt;
    for (const auto& [x, c] : mp) {
        b.push_back(x);
        cnt.push_back(c);
    }
    n = b.size();
    for (int i = n - 2; i >= 0; --i) {
        cnt[i] += cnt[i + 1];
    }
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    for (int j = 0; j < m; ++j) {
        auto f = [&](ll i) {
            return (b[i] + c[j]) * cnt[i];
        };
        ll l = 0, h = n - 1;
        while (h - l >= 3) {
            ll m1 = (l + h) / 2, m2 = (m1 + h) / 2;
            ll f1 = f(m1), f2 = f(m2);
            if (f1 < f2) {
                l = m1;
            } else {
                h = m2;
            }
        }
        ll ans = 0;
        for (int i = l; i <= h; ++i) {
            ans = max(ans, f(i));
        }
        cout << ans << ' ';
    }
    cout << '\n';
    return 0;
}
