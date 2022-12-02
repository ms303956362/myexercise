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
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> fa(n);
        vector<vector<int>> g(n);
        for (int i = 1; i < n; ++i) {
            int p;
            cin >> p;
            --p;
            fa[i] = p;
            g[p].push_back(i);
        }
        function<int(int, int, int&)> dfs = [&](int u, int m, int& cnt) -> int {
            int h = 0;
            for (const auto& v : g[u]) {
                h = max(h, dfs(v, m, cnt) + 1);
            }
            if (h == m - 1 && u != 0 && fa[u] != 0) {
                ++cnt;
                h = -1;
            }
            return h;
        };
        auto check = [&](int m) -> bool {
            int cnt = 0;
            dfs(0, m, cnt);
            return cnt <= k;
        };
        int l = 1, h = n;
        while (l <= h) {
            int m = (l + h) / 2;
            if (check(m)) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        cout << l << endl;
    }
    return 0;
}
