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
    vector<vector<int>> g(400005);
    vector<bool> vst(400005, true);
    set<pair<int, int>> e;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        vst[a] = false;
        vst[b] = false;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt = 0, cnte = 0, ans = 0;
    function<void(int)> dfs = [&](int u) {
        vst[u] = true;
        ++cnt;
        for (const auto& v : g[u]) {
            ++cnte;
            if (!vst[v]) {
                dfs(v);
            }
        }
    };
    for (int i = 1; i <= 400005; ++i) {
        if (!vst[i]) {
            cnt = 0;
            cnte = 0;
            dfs(i);
            cnte /= 2;
            ans += min(cnt, cnte);
        }
    }
    cout << ans << '\n';
    return 0;
}
