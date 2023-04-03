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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] == 'Y') {
                g[i].push_back(j);
            }
        }
    }
    vector<vector<ll>> times(n, vector<ll>(n, 0x3f3f3f3f3f3f3f3f)), money(n, vector<ll>(n, 0x3f3f3f3f3f3f3f3f));
    auto bfs = [&](int u) {
        vector<ll> &t = times[u], &m = money[u];
        vector<bool> vst(n);
        queue<int> q;
        q.push(u);
        t[u] = 0;
        m[u] = a[u];
        vst[u] = true;
        while (!q.empty()) {
            int l = q.size();
            for (int i = 0; i < l; ++i) {
                int v = q.front();
                q.pop();
                for (const auto& w : g[v]) {
                    if (t[w] > t[v] + 1) {
                        t[w] = t[v] + 1;
                        m[w] = m[v] + a[w];
                    } else if (t[w] == t[v] + 1) {
                        m[w] = max(m[w], m[v] + a[w]);
                    }
                    if (!vst[w]) {
                        vst[w] = true;
                        q.push(w);
                    }
                }
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        bfs(i);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (times[u][v] == 0x3f3f3f3f3f3f3f3f) {
            cout << "Impossible" << '\n';
        } else {
            cout << times[u][v] << " " << money[u][v] << '\n';
        }
    }
    return 0;
}
