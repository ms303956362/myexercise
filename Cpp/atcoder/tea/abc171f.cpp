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

ll pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k;
    cin >> k;
    string s;
    cin >> s;
    ll n = s.size(), mod = 1e9 + 7;
    vector<ll> p26(k + 1), p25(k + 1);
    p26[0] = 1;
    p25[0] = 1;
    for (int i = 1; i <= k; ++i) {
        p26[i] = (p26[i - 1] * 26) % mod;
        p25[i] = (p25[i - 1] * 25) % mod;
    }
    ll ans = 0, c = 1;
    for (int i = 0; i <= k; ++i) {
        ans = (ans + ((p26[k - i] * c) % mod * p25[i]) % mod) % mod;
        c = ((c * (n + i)) % mod * pow(i + 1, mod - 2, mod)) % mod;
    }
    cout << ans << endl;
    return 0;
}
