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
    vector<ll> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(2));
    for (int i = 1; i <= n; ++i) {
        if (x[i] == 0) {
            dp[i][0] = max({dp[i - 1][0], dp[i - 1][0] + y[i], dp[i - 1][1] + y[i]});
            dp[i][1] = dp[i - 1][1];
        } else {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + y[i]);
        }
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
    return 0;
}
