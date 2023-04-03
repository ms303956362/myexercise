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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> sum(n + 1), dp(n);
    for (int k = 1; k <= n; ++k) {
        sum[k] = sum[k - 1] + a[(k - 1) / 2];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            dp[i] = max(dp[i], dp[j] + sum[i - j - 1]);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[i] + sum[n - i - 1]);
    }
    cout << ans << '\n';
    return 0;
}
