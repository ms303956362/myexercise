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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    vector<bool> has(n, false);
    for (int i = 0; i < m; ++i) {
        int u, v, a;
        cin >> u >> v >> a;
        g[u - 1].emplace_back(v - 1, a);
        g[v - 1].emplace_back(u - 1, a);
    }
    for (int i = 0; i < k; ++i) {
        int s;
        cin >> s;
        has[s - 1] = true;
    }
    vector<vector<bool>> vst(n, vector<bool>(2));
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    vst[0][0] = true;
    int ans = -1, step = 0;
    while (!q.empty()) {
        int l = q.size();
        for (int i = 0; i < l; ++i) {
            auto [u, s] = q.front();
            q.pop();
            if (u == n - 1) {
                ans = step;
                break;
            }
            if (!has[u]) {
                for (const auto& [v, a] : g[u]) {
                    if ((a ^ s) == 1 && !vst[v][s]) {
                        vst[v][s] = true;
                        q.emplace(v, s);
                    }
                }
            } else {
                for (const auto& [v, a] : g[u]) {
                    if ((a ^ s) == 1 && !vst[v][s]) {
                        vst[v][s] = true;
                        q.emplace(v, s);
                    } else if ((a ^ s) == 0 && !vst[v][1 - s]) {
                        vst[v][1 - s] = true;
                        q.emplace(v, 1 - s);
                    }
                }
            }
        }
        if (ans != -1) {
            break;
        }
        ++step;
    }
    cout << ans << endl;
    return 0;
}
