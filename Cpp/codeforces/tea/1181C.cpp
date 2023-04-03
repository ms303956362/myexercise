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
    int m, n;
    cin >> m >> n;
    vector<string> grid(m);
    for (int i = 0; i < m; ++i) {
        cin >> grid[i];
    }
    vector<vector<pair<string, int>>> dp1(m, vector<pair<string, int>>(n));
    for (int j = 0; j < n; ++j) {
        vector<pair<char, int>> a;
        for (int i = m - 1; i >= 0; --i) {
            if (i == m - 1 || grid[i][j] != grid[i + 1][j]) {
                a.emplace_back(grid[i][j], 1);
            } else {
                ++a.back().second;
            }
            int l = a.size();
            if (l >= 3 && a[l - 1].second == a[l - 2].second && a[l - 2].second <= a[l - 3].second) {
                dp1[i][j] = make_pair(string{a[l - 1].first, a[l - 2].first, a[l - 3].first}, a[l - 1].second);
            }
        }
    }
    vector<vector<ll>> dp2(m, vector<ll>(n));
    ll ans = 0;
    for (int j = n - 1; j >= 0; --j) {
        for (int i = m - 1; i >= 0; --i) {
            if (dp1[i][j] != make_pair(string(""), 0)) {
                ++dp2[i][j];
                if (j < n - 1 && dp1[i][j] == dp1[i][j + 1]) {
                    dp2[i][j] += dp2[i][j + 1];
                }
                ans += dp2[i][j];
            }
        }
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
