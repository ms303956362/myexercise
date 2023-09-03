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
#include <numeric>
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
    vector<ll> a(n), pre(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0 && i % 2 == 0) {
            pre[i] = pre[i - 1] + a[i] - a[i - 1];
        } else {
            pre[i] = pre[i - 1];
        }
    }
    int q;
    cin >> q;
    vector<ll> b;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int il = lower_bound(a.begin(), a.end(), l) - a.begin(), ir = upper_bound(a.begin(), a.end(), r) - a.begin() - 1;
        ll ans = pre[ir] - pre[il];
        if (il % 2 == 0) {
            ans += a[il] - l;
        }
        if (ir % 2 == 1) {
            ans += r - a[ir];
        }
        b.push_back(ans);
    }
    for (const auto& ans : b) {
        cout << ans << '\n';
    }
    return 0;
}
