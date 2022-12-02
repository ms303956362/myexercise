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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<ll> st(a.begin(), a.end());
    vector<ll> b(st.begin(), st.end());
    if (b.size() == 1) {
        cout << 0 << endl;
        return;
    }
    if (b.size() == 2) {
        cout << 2 * (b[1] - b[0]) << endl;
        return;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 1) {
            ans = max(ans, a[i] - a[0] + a[i] - a[i - 1]);
        }
        if (i < n - 2) {
            ans = max(ans, a[n - 1] - a[i] + a[i + 1] - a[i]);
        }
    }
    cout << ans << endl;
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
