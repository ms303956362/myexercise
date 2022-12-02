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
    int n, q;
    cin >> n >> q;
    vector<int> a(n), pre(n + 1);
    vector<ll> pres(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    unordered_map<int, set<int>> idx[2];
    for (int i = n - 1; i >= 0; --i) {
        pre[i] = pre[i + 1] ^ a[i];
        pres[i] = pres[i + 1] + a[i];
        idx[i % 2][pre[i]].insert(i);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        if (pre[l] ^ pre[r + 1]) {
            cout << -1 << endl;
        } else {
            if (pres[l] - pres[r + 1] == 0) {
                cout << 0 << endl;
            } else if ((r - l + 1) % 2 == 1) {
                cout << 1 << endl;
            } else if (a[l] == 0 || a[r] == 0) {
                cout << 1 << endl;
            } else {
                auto p = idx[1 - l % 2][pre[l]].upper_bound(l);
                if (p != idx[1 - l % 2][pre[l]].end() && *p <= r + 1) {
                    cout << 2 << endl;
                } else {
                    cout << -1 << endl;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
