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
    int n;
    cin >> n;
    vector<ll> z(n), c(n);
    int sz = 0;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y >> z[i];
        sz += z[i];
        c[i] = max((x + y + 1) / 2 - x, 0LL);
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(sz + 1, 0x3f3f3f3f3f3f3f3f));
    dp[n][0] = 0;
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = dp[i + 1];
        for (int j = z[i]; j <= sz; ++j) {
            dp[i][j] = min(dp[i][j], dp[i + 1][j - z[i]] + c[i]);
        }
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int j = (sz + 1) / 2; j <= sz; ++j) {
        ans = min(ans, dp[0][j]);
    }
    cout << ans << '\n';
    return 0;
}
