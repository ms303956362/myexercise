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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(k, vector<int>(n + 1));
    for (int j = 1; j <= n; ++j) {
        dp[0][j] = 1;
    }
    int mod = 1e9 + 7;
    for (int i = 1; i < k; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int t = 1; t * t <= j; ++t) {
                if (j % t == 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][t]) % mod;
                    if (j / t != t) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j / t]) % mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= n; ++j) {
        ans = (ans + dp[k - 1][j]) % mod;
    }
    cout << ans << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
