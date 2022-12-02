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
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int p;
        cin >> p;
        g[p - 1].push_back(i + 1);
    }
    function<pair<int, int>(int)> dfs = [&](int u) {
        int max_h = 1, sum = 0;
        for (const auto& v : g[u]) {
            auto [h, s] = dfs(v);
            max_h = max(max_h, h + 1);
            sum += max(h, s);
        }
        return make_pair(max_h, sum);
    };
    auto [h, s] = dfs(0);
    cout << max(h, s) << endl;
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
