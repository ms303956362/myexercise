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

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll mod = 998244353;
    ll n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    ll invp = pow(p, mod - 2, mod), invq = pow(q, mod - 2, mod);
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(2, -1)));
    function<void(ll, ll, ll)> dfs = [&](ll x, ll y, ll k) {
        if (dp[x][y][k] != -1) {
            return;
        }
        dp[x][y][k] = 0;
        if (k == 0) {
            for (ll i = 1; i <= p; ++i) {
                if (x + i >= n) {
                    dp[x][y][k] = (dp[x][y][k] + invp) % mod;
                } else {
                    dfs(x + i, y, 1 - k);
                    dp[x][y][k] = ((dp[x][y][k] + invp - invp * dp[x + i][y][1 - k]) % mod + mod) % mod;
                }
            }
        } else {
            for (ll i = 1; i <= q; ++i) {
                if (y + i >= n) {
                    dp[x][y][k] = (dp[x][y][k] + invq) % mod;
                } else {
                    dfs(x, y + i, 1 - k);
                    dp[x][y][k] = ((dp[x][y][k] + invq - invq * dp[x][y + i][1 - k]) % mod + mod) % mod;
                }
            }
        }
    };
    dfs(a, b, 0);
    cout << dp[a][b][0] << '\n';
    return 0;
}
