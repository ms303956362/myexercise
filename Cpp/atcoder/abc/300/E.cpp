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
    ll ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = (ret * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

const ll mod = 998244353;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll inv5 = pow(5, mod - 2, mod);
    unordered_map<ll, ll> dp;
    function<void(ll)> dfs = [&](ll i) {
        if (dp.count(i)) {
            return;
        }
        dp[i] = 0;
        if (i > n) {
            return;
        }
        if (i == n) {
            dp[i] = 1;
            return;
        }
        for (ll k = 2; k <= 6; ++k) {
            dfs(k * i);
            dp[i] = (dp[i] + (dp[k * i] * inv5) % mod) % mod;
        }
    };
    dfs(1);
    cout << dp[1] << '\n';
    return 0;
}
