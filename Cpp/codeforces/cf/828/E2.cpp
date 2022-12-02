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
    vector<ll> factors1, factors2;
    for (ll x = 1; x * x <= a; ++x) {
        if (a % x == 0) {
            factors1.push_back(x);
            if (x * x != a) {
                factors1.push_back(a / x);
            }
        }
    }
    for (ll x = 1; x * x <= b; ++x) {
        if (b % x == 0) {
            factors2.push_back(x);
            if (x * x != b) {
                factors2.push_back(b / x);
            }
        }
    }
    set<ll> st;
    for (const auto& f1 : factors1) {
        for (const auto& f2 : factors2) {
            st.insert(f1 * f2);
        }
    }
    vector<ll> factors(st.begin(), st.end());
    auto check = [&](ll f, ll g) {
        ll k1 = a / f + 1, k2 = b / g + 1;
        if (k1 * f > c || k2 * g > d) {
            return make_pair(-1LL, -1LL);
        }
        return make_pair(k1, k2);
    };
    bool ok = false;
    for (const auto& f : factors) {
        ll g = (a * b) / f;
        auto pr = check(f, g);
        if (pr != make_pair(-1LL, -1LL)) {
            cout << pr.first * f << " " << pr.second * g << endl;
            ok = true;
            break;
        }
        pr = check(g, f);
        if (pr != make_pair(-1LL, -1LL)) {
            cout << pr.first * g << " " << pr.second * f << endl;
            ok = true;
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
