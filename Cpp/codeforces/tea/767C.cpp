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
    vector<int> vals(n);
    vector<vector<int>> g(n);
    int root = 0, total = 0;
    for (int i = 0; i < n; ++i) {
        int f;
        cin >> f >> vals[i];
        total += vals[i];
        if (f > 0) {
            g[f - 1].push_back(i);
        } else {
            root = i;
        }
    }
    if (total % 3 != 0) {
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    function<int(int, int)> dfs = [&](int u, int f) {
        int sum = vals[u];
        for (const auto& v : g[u]) {
            if (v == f) {
                continue;
            }
            sum += dfs(v, u);
        }
        if (sum == total / 3 && u != root) {
            ans.push_back(u);
            return 0;
        }
        return sum;
    };
    dfs(root, -1);
    if (ans.size() < 2) {
        cout << -1 << endl;
        return;
    }
    cout << ans[0] + 1 << " " << ans[1] + 1 << endl;
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
