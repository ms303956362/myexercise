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
    vector<int> p(n, -1), l(n), r(n), v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i] >> l[i] >> r[i];
        --l[i];
        --r[i];
        if (l[i] >= 0) {
            p[l[i]] = i;
        }
        if (r[i] >= 0) {
            p[r[i]] = i;
        }
    }
    int root = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] == -1) {
            root = i;
            break;
        }
    }
    multiset<int> sl, sr;
    set<int> st;
    function<void(int)> dfs = [&](int u) {
        if ((sl.empty() || v[u] < *sl.begin()) && (sr.empty() || v[u] >= *sr.rbegin())) {
            st.insert(v[u]);
        }
        if (l[u] >= 0) {
            sl.insert(v[u]);
            dfs(l[u]);
            sl.extract(v[u]);
        }
        if (r[u] >= 0) {
            sr.insert(v[u]);
            dfs(r[u]);
            sr.extract(v[u]);
        }
    };
    dfs(root);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!st.count(v[i])) {
            ++ans;
        }
    }
    cout << ans << endl;
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
