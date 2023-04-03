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
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    for (int i = 0; i < n; ++i) {
        int y;
        cin >> y;
    }
    vector<ll> dp1(n), dp2(n);
    int i = 0, j = 0;
    while (i < n) {
        while (j < i && x[j] < x[i] - k) {
            ++j;
        }
        dp1[i] = i - j + 1;
        ++i;
    }
    priority_queue<ll> q;
    ll ans = 0;
    i = 0, j = 0;
    while (i < n) {
        while (j < i && x[j] < x[i] - k) {
            q.push(dp1[j]);
            ++j;
        }
        if (!q.empty()) {
            dp2[i] = q.top() + (i - j + 1);
        } else {
            dp2[i] = dp1[i];
        }
        ans = max(ans, dp2[i]);
        ++i;
    }
    cout << ans << '\n';
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
