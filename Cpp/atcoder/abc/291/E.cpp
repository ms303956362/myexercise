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
    set<pair<int, int>> vst;
    vector<int> in(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        if (vst.count(make_pair(x, y))) {
            continue;
        }
        vst.emplace(x, y);
        g[x].push_back(y);
        ++in[y];
    }
    bool ok = true;
    vector<int> a(n, -1);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    int num = 1;
    while (!q.empty()) {
        if (q.size() > 1) {
            ok = false;
            break;
        }
        auto u = q.front();
        q.pop();
        a[u] = num;
        ++num;
        for (const auto& v : g[u]) {
            --in[v];
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
