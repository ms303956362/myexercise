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
    vector<int> s(n), t(m);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> t[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    dp[n][m] = 1;
    for (int i = 0; i <= n; ++i) {
        dp[i][m] = 1;
    }
    for (int i = 0; i <= m; ++i) {
        dp[n][i] = 1;
    }
    ll mod = 1e9 + 7;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (s[i] != t[j]) {
                dp[i][j] = ((dp[i][j + 1] + dp[i + 1][j] - dp[i + 1][j + 1]) % mod + mod) % mod;
            } else {
                dp[i][j] = (dp[i][j + 1] + dp[i + 1][j]) % mod;
            }
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
