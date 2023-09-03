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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    for (int i = 0; i < n; ++i) {
        g[n].emplace_back(i, 0);
    }
    vector<bool> vst(n);
    int ans = 0, l = 0;
    function<void(int)> dfs = [&](int u) {
        ans = max(ans, l);
        for (const auto& [v, c] : g[u]) {
            if (!vst[v]) {
                vst[v] = true;
                l += c;
                dfs(v);
                l -= c;
                vst[v] = false;
            }
        }
    };
    dfs(n);
    cout << ans << '\n';
    return 0;
}
