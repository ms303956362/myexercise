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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> x(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
    }
    vector<pair<ll, int>> sv(n);
    ll total = 0, max_sum = -1e18;
    for (int i = 0; i < n; ++i) {
        total += a[i];
        sv[i] = make_pair(total, i);
        max_sum = max(max_sum, total);
    }
    sort(sv.rbegin(), sv.rend());
    vector<ll> ans(m);
    vector<pair<ll, int>> xv;
    for (int i = 0; i < m; ++i) {
        if (max_sum < x[i]) {
            if (total <= 0) {
                ans[i] = -1;
            } else {
                ll turn = (x[i] - max_sum + total - 1) / total;
                ans[i] += turn * n;
                x[i] -= turn * total;
                xv.emplace_back(x[i], i);
            }
        } else {
            xv.emplace_back(x[i], i);
        }
    }
    sort(xv.rbegin(), xv.rend());
    set<int> st;
    int j = 0, l = xv.size();
    for (int i = 0; i < l; ++i) {
        while (j < n && sv[j].first >= xv[i].first) {
            st.insert(sv[j].second);
            ++j;
        }
        ans[xv[i].second] += *st.begin();
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
