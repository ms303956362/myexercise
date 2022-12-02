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
    vector<vector<tuple<int, int, int>>> segs(n + 1);
    vector<int> ans(n + 1, 0x3f3f3f3f);
    for (int i = 0; i < n; ++i) {
        int l, r, c;
        cin >> l >> r >> c;
        segs[c].emplace_back(l, r, i);
    }
    set<int> starts, ends;
    for (int j = n; j >= 1; --j) {
        for (const auto& [l, r, i] : segs[j]) {
            auto p1 = starts.upper_bound(r);
            if (p1 != starts.end()) {
                ans[i] = min(ans[i], *p1 - r);
            }
            if (p1 != starts.begin()) {
                auto q = prev(p1);
                if (q != starts.end() && l <= *q && *q <= r) {
                    ans[i] = 0;
                }
            }
            auto p2 = ends.lower_bound(l);
            if (p2 != ends.end() && l <= *p2 && *p2 <= r) {
                ans[i] = 0;
            }
            if (p2 != ends.begin()) {
                auto q = prev(p2);
                if (q != ends.end()) {
                    ans[i] = min(ans[i], l - *q);
                }
            }
        }
        for (const auto& [l, r, i] : segs[j]) {
            starts.insert(l);
            ends.insert(r);
        }
    }
    starts.clear();
    ends.clear();
    for (int j = 1; j <= n; ++j) {
        for (const auto& [l, r, i] : segs[j]) {
            auto p1 = starts.upper_bound(r);
            if (p1 != starts.end()) {
                ans[i] = min(ans[i], *p1 - r);
            }
            if (p1 != starts.begin()) {
                auto q = prev(p1);
                if (q != starts.end() && l <= *q && *q <= r) {
                    ans[i] = 0;
                }
            }
            auto p2 = ends.lower_bound(l);
            if (p2 != ends.end() && l <= *p2 && *p2 <= r) {
                ans[i] = 0;
            }
            if (p2 != ends.begin()) {
                auto q = prev(p2);
                if (q != ends.end()) {
                    ans[i] = min(ans[i], l - *q);
                }
            }
        }
        for (const auto& [l, r, i] : segs[j]) {
            starts.insert(l);
            ends.insert(r);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i - 1] << " ";
    }
    cout << endl;
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
