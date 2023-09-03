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
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u ,w);
    }
    vector<int> ans(n, -1), dis(n, 0x3f3f3f3f);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        --a;
        q.emplace(0, a);
        dis[a] = 0;
        ans[a] = 0;
    }
    int d;
    cin >> d;
    vector<int> x(d);
    for (int i = 0; i < d; ++i) {
        cin >> x[i];
    }
    int day = 1;
    while (!q.empty()) {
        int l = q.size();
        while (l--) {
            auto [d, u] = q.top();
            q.pop();
            if (d > dis[u]) {
                continue;
            }
            for (const auto& [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    if (d + w <= x[day - 1] && ans[v] == -1) {
                        ans[v] = day;
                    }
                    dis[v] = d + w;
                    q.emplace(d + 1, v);
                }
            }
        }
        ++day;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
