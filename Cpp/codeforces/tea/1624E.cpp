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
    int n, m;
    cin >> n >> m;
    unordered_map<string, tuple<int, int, int>> mp;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j <= m - 2; ++j) {
            mp[s.substr(j, 2)] = make_tuple(j + 1, j + 2, i + 1);
        }
        for (int j = 0; j <= m - 3; ++j) {
            mp[s.substr(j, 3)] = make_tuple(j + 1, j + 3, i + 1);
        }
    }
    string s;
    cin >> s;
    vector<bool> dp(m + 1);
    dp[m] = true;
    if (m - 2 >= 0) {
        dp[m - 2] = mp.count(s.substr(m - 2, 2));
    }
    for (int i = m - 3; i >= 0; --i) {
        dp[i] = (mp.count(s.substr(i, 3)) && dp[i + 3]) || (mp.count(s.substr(i, 2)) && dp[i + 2]);
    }
    if (!dp[0]) {
        cout << -1 << '\n';
        return;
    }
    int i = 0;
    vector<tuple<int, int, int>> ans;
    while (i < m) {
        if (i + 2 <= m && dp[i + 2]) {
            ans.push_back(mp[s.substr(i, 2)]);
            i += 2;
        } else {
            ans.push_back(mp[s.substr(i, 3)]);
            i += 3;
        }
    }
    cout << ans.size() << '\n';
    for (const auto& [l, r, k] : ans) {
        cout << l << ' ' << r << ' ' << k << '\n';
    }
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
