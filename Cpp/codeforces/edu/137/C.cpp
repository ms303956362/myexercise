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
    string l;
    cin >> l;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(2));
    if (l[0] == '1') {
        dp[0][0] = 0xff3f3f3f3f3f3f3f;
        dp[0][1] = a[0];
    } else {
        dp[0][0] = 0;
        dp[0][1] = 0xff3f3f3f3f3f3f3f;
    }
    for (int i = 1; i < n; ++i) {
        if (l[i] == '0') {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = 0xff3f3f3f3f3f3f3f;
        } else {
            dp[i][0] = max(a[i - 1] + dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
        }
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
