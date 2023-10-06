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
#include <numeric>
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
    ll q, k;
    cin >> q >> k;
    ll mod = 998244353;
    vector<ll> dp(k + 5005);
    dp[0] = 1;
    while (q--) {
        char op;
        cin >> op;
        ll x;
        cin >> x;
        vector<ll> ndp(dp);
        if (op == '+') {
            for (ll i = x; i < k + 5005; ++i) {
                ndp[i] = (ndp[i] + dp[i - x]) % mod;
            }
        } else {
            for (ll i = x; i < k + 5005; ++i) {
                ndp[i] = ((ndp[i] - ndp[i - x]) % mod + mod) % mod;
            }
        }
        dp = ndp;
        cout << dp[k] << '\n';
    }
    return 0;
}
