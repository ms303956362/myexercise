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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, ll> cnt;
    vector<int> pre(n + 1);
    ++cnt[0];
    int mask = (1 << k) - 1;
    for (int i = n - 1; i >= 0; --i) {
        pre[i] = pre[i + 1] ^ a[i];
        ++cnt[min(pre[i], mask - pre[i])];
    }
    ll ans = n * (n + 1) / 2;
    for (const auto& [num, c] : cnt) {
        ll s = c, t = s / 2, r = s - s / 2;
        ans -= t * (t - 1) / 2 + r * (r - 1) / 2;
    }
    cout << ans << '\n';
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
