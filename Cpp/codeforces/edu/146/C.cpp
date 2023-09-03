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
    ll n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        v.emplace_back(x, i + 1);
    }
    sort(v.rbegin(), v.rend());
    ll i1 = 1, i2 = 1;
    vector<ll> a, b;
    for (int i = 0; i < n; ++i) {
        auto [r, idx] = v[i];
        if (i1 * s1 <= i2 * s2) {
            a.push_back(idx);
            ++i1;
        } else {
            b.push_back(idx);
            ++i2;
        }
    }
    cout << a.size() << ' ';
    for (const auto& idx : a) {
        cout << idx << ' ';
    }
    cout << '\n';
    cout << b.size() << ' ';
    for (const auto& idx : b) {
        cout << idx << ' ';
    }
    cout << '\n';
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
