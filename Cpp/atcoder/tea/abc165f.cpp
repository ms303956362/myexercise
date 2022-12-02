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
    vector<vector<int>> g(n), st(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    vector<int> d, idx(n);
    vector<int> ans(n);
    function<void(int, int)> dfs = [&](int u, int f) {
        if (d.empty() || d.back() < a[u]) {
            st[d.size()].push_back(a[u]);
            idx[u] = d.size();
            d.push_back(a[u]);
        } else {
            int j = lower_bound(d.begin(), d.end(), a[u]) - d.begin();
            st[j].push_back(a[u]);
            d[j] = a[u];
            idx[u] = j;
        }
        ans[u] = d.size();
        for (const auto& v : g[u]) {
            if (v == f) {
                continue;
            }
            dfs(v, u);
        }
        st[idx[u]].pop_back();
        if (st[idx[u]].empty()) {
            d.pop_back();
        } else {
            d[idx[u]] = st[idx[u]].back();
        }
    };
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
