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
    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    vector<ll> pre(m + 1);
    for (int i = m - 1; i >= 0; --i) {
        pre[i] = pre[i + 1] + b[i];
    }
    ll ans = 0;
    for (const auto& num : a) {
        ll k = upper_bound(b.begin(), b.end(), p - num) - b.begin();
        ans += (m - k) * p + pre[0] - pre[k] + k * num;
    }
    cout << ans << '\n';
    return 0;
}
