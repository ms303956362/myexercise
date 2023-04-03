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
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].emplace_back(v, 0);
        g[v].emplace_back(u, 1);
    }
    vector<int> dp(n);
    function<int(int, int)> dfs1 = [&](int u, int f) {
        int ret = 0;
        for (const auto& [v, d] : g[u]) {
            if (v == f) {
                continue;
            }
            ret += dfs1(v, u) + d;
        }
        return ret;
    };
    dp[0] = dfs1(0, -1);
    function<void(int, int)> dfs2 = [&](int u, int f) {
        for (const auto& [v, d] : g[u]) {
            if (v == f) {
                continue;
            }
            dp[v] = dp[u] - d + (1 - d);
            dfs2(v, u);
        }
    };
    dfs2(0, -1);
    int min_inv = INT_MAX;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (dp[i] < min_inv) {
            min_inv = dp[i];
            ans.clear();
            ans.push_back(i);
        } else if (dp[i] == min_inv) {
            ans.push_back(i);
        }
    }
    cout << min_inv << '\n';
    for (const auto& u : ans) {
        cout << u + 1 << " ";
    }
    cout << '\n';
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
