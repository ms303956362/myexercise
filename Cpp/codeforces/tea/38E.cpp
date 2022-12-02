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

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    vector<ll> x(n), c(n), dp(n, 0x3f3f3f3f3f3f3f3f);
    for (int i = 0; i < n; ++i) {
        x[i] = a[i].first;
        c[i] = a[i].second;
    }
    for (int i = 0; i < n; ++i) {
        ll dis = 0;
        for (int j = i; j < n; ++j) {
            dis += x[j] - x[i];
            dp[j] = min(dp[j], (i == 0 ? 0 : dp[i - 1]) + dis + c[i]);
        }
    }
    cout << dp[n - 1] << endl;
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
