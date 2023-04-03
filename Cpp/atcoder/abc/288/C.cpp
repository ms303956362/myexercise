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
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    function<int(int)> find = [&](int u) {
        return p[u] == u ? u : (p[u] = find(p[u]));
    };
    auto merge = [&](int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) {
            return false;
        }
        p[pu] = pv;
        return true;
    };
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        if (!merge(x, y)) {
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}
