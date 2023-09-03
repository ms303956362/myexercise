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
    int n, q;
    cin >> n >> q;
    vector<unordered_set<int>> g(n);
    int ans = n;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            if (g[u].empty()) {
                --ans;
            }
            if (g[v].empty()) {
                --ans;
            }
            g[u].insert(v);
            g[v].insert(u);
        } else {
            int v;
            cin >> v;
            --v;
            for (const auto& u : g[v]) {
                g[u].erase(v);
                if (g[u].empty()) {
                    ++ans;
                }
            }
            if (!g[v].empty()) {
                g[v].clear();
                ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
