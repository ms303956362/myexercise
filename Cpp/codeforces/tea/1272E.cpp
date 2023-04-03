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
    vector<int> a(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
        if (i - x >= 0) {
            g[i - x].push_back(i);
        }
        if (i + x < n) {
            g[i + x].push_back(i);
        }
    }
    vector<int> d(n, -1);
    function<void(int)> bfs = [&](int c) {
        vector<bool> vst(n);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == c) {
                q.push(i);
                vst[i] = true;
            }
        }
        int step = 0;
        while (!q.empty()) {
            int l = q.size();
            for (int i = 0; i < l; ++i) {
                int u = q.front();
                q.pop();
                if (a[u] % 2 == 1 - c) {
                    d[u] = step;
                }
                for (const auto& v : g[u]) {
                    if (!vst[v]) {
                        q.push(v);
                        vst[v] = true;
                    }
                }
            }
            ++step;
        }
    };
    bfs(0);
    bfs(1);
    for (int i = 0; i < n; ++i) {
        cout << d[i] << ' ';
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
