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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    ll mod = 998244353;
    vector<vector<ll>> dp(n + 1, vector<ll>(2));
    dp[n - 1][0] = dp[n - 1][1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] != a[i + 1]) {
            dp[i][0] = (dp[i][0] + dp[i + 1][0]) % mod;
        }
        if (a[i] != b[i + 1]) {
            dp[i][0] = (dp[i][0] + dp[i + 1][1]) % mod;
        }
        if (b[i] != a[i + 1]) {
            dp[i][1] = (dp[i][1] + dp[i + 1][0]) % mod;
        }
        if (b[i] != b[i + 1]) {
            dp[i][1] = (dp[i][1] + dp[i + 1][1]) % mod;
        }
    }
    cout << (dp[0][0] + dp[0][1]) % mod << '\n';
    return 0;
}
