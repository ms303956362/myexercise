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
    string s;
    cin >> s;
    vector<vector<int>> nxt{{0, 3, 4}, {1, 5, 2}, {2, 1, 5}, {3, 4, 0}, {4, 0, 3}, {5, 2, 1}}, dp(n + 1, vector<int>(6));
    string s1("aabbcc"), s2("bcacab");
    dp[n - 1][0] = dp[n - 1][1] = (s[n - 1] != 'a');
    dp[n - 1][2] = dp[n - 1][3] = (s[n - 1] != 'b');
    dp[n - 1][4] = dp[n - 1][5] = (s[n - 1] != 'c');
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < 6; ++j) {
            dp[i][j] = (s[i] != s1[j]) + (s[i + 1] != s2[j]) + dp[i + 2][nxt[j][2]];
        }
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        int ans = 0x3f3f3f3f;
        for (int j = 0; j < 6; ++j) {
            ans = min(ans, dp[l][j] - dp[r + 1][nxt[j][(r + 1 - l) % 3]]);
        }
        cout << ans << '\n';
    }
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
