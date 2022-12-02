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
    ll n;
    cin >> n;
    unordered_map<ll, unordered_map<ll, ll>> cnt1, cnt2;
    ll cnt0 = 0, left = 0;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            ++cnt0;
            continue;
        } else if (a == 0 && b != 0) {
            b = 1;
            ++cnt2[a][b];
            ++left;
            continue;
        } else if (a != 0 && b == 0) {
            a = 1;
            ++cnt1[a][b];
            continue;
        }
        if (b < 0) {
            a = -a;
            b = -b;
        }
        ll g = __gcd(abs(a), abs(b));
        a /= g;
        b /= g;
        if (a > 0) {
            ++cnt1[a][b];
        } else {
            ++cnt2[a][b];
            ++left;
        }
    }
    ll ans = 1, mod = 1000000007;
    vector<ll> pow(n + 1);
    pow[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        pow[i] = (pow[i - 1] * 2) % mod;
    }
    for (const auto& [x, p] : cnt1) {
        for (const auto& [y, c] : p) {
            ans = (ans * ((pow[c] + pow[cnt2[-y][x]] - 1) % mod)) % mod;
            left -= cnt2[-y][x];
        }
    }
    ans = (ans * pow[left] % mod + cnt0 - 1 + mod) % mod;
    cout << ans << endl;
    return 0;
}
