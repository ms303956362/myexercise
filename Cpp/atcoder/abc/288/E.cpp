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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), c(n), pre(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        pre[i] = pre[i + 1] + a[i];
    }
    vector<bool> buy(n + 1);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        --x;
        buy[x] = true;
    }
    buy[n] = true;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = n - 1; i >= 0; --i) {
        if (!buy[i]) {
            continue;
        }
        int i_next = i + 1;
        while (i_next < n && !buy[i_next]) {
            ++i_next;
        }
        ans = 0x3f3f3f3f3f3f3f3f;
        dp[i][i] = a[i] + c[i] + dp[i_next][i];
        ans = min(ans, dp[i][i]);
        for (int j = i - 1; j >= 0; --j) {
            dp[i][j] = min(dp[i][j + 1], pre[j] - pre[i + 1] + (i + 1 - j) * c[j] + dp[i_next][j + 1]);
            ans = min(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}
