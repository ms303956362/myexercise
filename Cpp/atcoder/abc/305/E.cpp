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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> ttl(n, -1);
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < k; ++i) {
        int p, h;
        cin >> p >> h;
        --p;
        ttl[p] = h;
        q.emplace(h, p);
    }
    while (!q.empty()) {
        auto [t, u] = q.top();
        q.pop();
        if (ttl[u] < t) {
            continue;
        }
        for (const auto& v : g[u]) {
            if (ttl[v] < t - 1) {
                ttl[v] = t - 1;
                q.emplace(ttl[v], v);
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (ttl[i] >= 0) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << '\n';
    for (const auto& u : ans) {
        cout << u << ' ';
    }
    cout << '\n';
    return 0;
}
