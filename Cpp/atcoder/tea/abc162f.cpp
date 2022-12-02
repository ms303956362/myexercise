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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(3, 0xff3f3f3f3f3f3f3f));
    dp[n - 1][0] = a[n - 1];
    dp[n - 2][0] = a[n - 2];
    if (n > 2) {
        dp[n - 3][0] = dp[n - 1][0] + a[n - 3];
        dp[n - 3][1] = a[n - 3];
    }
    for (int i = n - 4; i >= 0; --i) {
        dp[i][0] = dp[i + 2][0] + a[i];
        dp[i][1] = max(dp[i + 2][1], dp[i + 3][0]) + a[i];
        dp[i][2] = max(dp[i + 2][2], dp[i + 3][1]) + a[i];
    }
    if (n % 2 == 0) {
        cout << max({dp[0][0], dp[0][1], dp[1][0]}) << endl;
    } else {
        cout << max({dp[0][1], dp[0][2], dp[1][0], dp[1][1], dp[2][0]}) << endl;
    }
    return 0;
}
