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

ll solve(ll n, ll m, vector<ll>& a) {
    sort(a.begin(), a.end());
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        a.push_back(a[i]);
        total += a[i];
    }
    vector<ll> pre(2 * n + 1);
    for (int i = 2 * n - 1; i >= 0; --i) {
        pre[i] = pre[i + 1] + a[i];
    }
    ll i = 0, ans = total;
    while (i < n) {
        ll j = i + 1;
        while (j < 2 * n && (a[j] == a[j - 1] || a[j] == (a[j - 1] + 1) % m)) {
            ++j;
        }
        if (j - i >= n) {
            return 0;
        }
        ans = min(ans, total - (pre[i] - pre[j]));
        i = j;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a[i] = x;
    }
    cout << solve(n, m, a) << endl;
    return 0;
}
