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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (m != n - 1) {
        cout << "No" << '\n';
        return 0;
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) {
            ++cnt1;
        } else {
            ++cnt2;
        }
    }
    if (cnt1 != 2 || cnt2 != n - 2) {
        cout << "No" << '\n';
        return 0;
    }
    vector<bool> vst(n);
    function<void(int)> dfs = [&](int u) {
        vst[u] = true;
        for (const auto& v : g[u]) {
            if (vst[v]) {
                continue;
            }
            dfs(v);
        }
    };
    dfs(0);
    for (int i = 0; i < n; ++i) {
        if (!vst[i]) {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';
    return 0;
}
