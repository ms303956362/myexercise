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
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<ll>> a(m, vector<ll>(n)), dp_max(m + 1, vector<ll>(n + 1));
    for (int i = 0; i < k; ++i) {
        int r, c, v;
        cin >> r >> c >> v;
        a[r - 1][c - 1] = v;
    }
    vector<vector<vector<ll>>> dp(m + 1, vector<vector<ll>>(n + 1, vector<ll>(4)));
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            dp[i][j][0] = max(dp_max[i + 1][j], dp[i][j + 1][0]);
            dp_max[i][j] = dp[i][j][0];
            if (a[i][j] > 0) {
                dp[i][j][1] = max({dp_max[i + 1][j] + a[i][j], dp[i][j + 1][0] + a[i][j], dp[i][j + 1][1]});
                dp_max[i][j] = max(dp_max[i][j], dp[i][j][1]);
                for (int t = 2; t < 4 && dp[i][j + 1][t - 1] > 0; ++t) {
                    dp[i][j][t] = max(dp[i][j + 1][t], dp[i][j + 1][t - 1] + a[i][j]);
                    dp_max[i][j] = max(dp_max[i][j], dp[i][j][t]);
                }
            } else {
                for (int t = 1; t < 4; ++t) {
                    dp[i][j][t] = dp[i][j + 1][t];
                    dp_max[i][j] = max(dp_max[i][j], dp[i][j][t]);
                }
            }
        }
    }
    cout << dp_max[0][0] << endl;
    return 0;
}
