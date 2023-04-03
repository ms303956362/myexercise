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
    // int n;
    // cin >> n;
    // vector<int> a(n), b(n);
    // for (int i = 0; i < n; ++i) {
    //     cin >> a[i];
    // }
    // for (int i = 0; i < n; ++i) {
    //     cin >> b[i];
    // }
    // function<pair<int, int>(vector<int>&, vector<int>&, int)> f = [&f](vector<int>&a, vector<int>& b, int k) {
    //     int n = a.size();
    //     vector<int> a0, a1, b0, b1;
    //     for (int i = 0; i < n; ++i) {
    //         if (a[i] & (1 << k)) {
    //             a1.push_back(a[i]);
    //         } else {
    //             a0.push_back(a[i]);
    //         }
    //         if (b[i] & (1 << k)) {
    //             b1.push_back(b[i]);
    //         } else {
    //             b0.push_back(b[i]);
    //         }
    //     }
    //     if (k == 0) {
    //         return make_pair(int(a0.size() == b1.size()), 0);
    //     }
    //     int ret1 = 0, ret2 = 0;
    //     if (a0.size() == b1.size()) {
    //         ret1 |= (1 << k);
    //         auto [ra1, ra2] = f(a0, b1, k - 1);
    //         auto [rb1, rb2] = f(a1, b0, k - 1);
    //         ret1 |= max({ra1 & rb1, ra1 & rb2, ra2 & rb1, ra2 & rb2});
    //     }
    //     auto [r1, r2] = f(a, b, k - 1);
    //     ret2 = max(r1, r2);
    //     ret1 = max(ret1, ret2);
    //     return make_pair(ret1, ret2);
    // };
    // auto [r1, r2] = f(a, b, 30);
    // cout << max(r1, r2) << '\n';
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    auto check = [&](int x) {
        vector<int> c, d;
        for (int i = 0; i < n; ++i) {
            c.push_back(a[i] & x);
        }
        for (int i = 0; i < n; ++i) {
            d.push_back(~b[i] & x);
        }
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());
        return c == d;
    };
    int ans = 0;
    for (int i = 30; i >= 0; --i) {
        if (check(ans | (1 << i))) {
            ans |= (1 << i);
        }
    }
    cout << ans << endl;
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
