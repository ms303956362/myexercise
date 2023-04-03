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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v;
    vector<ll> va, prea(m + 1);
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
        va.push_back(a);
    }
    sort(va.begin(), va.end());
    for (int i = m - 1; i >= 0; --i) {
        prea[i] = prea[i + 1] + va[i];
    }
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        ll sum = 0, cnt_max = n;
        if (v[i].first < v[i].second) {
            sum = v[i].first;
            cnt_max = n - 1;
        }
        int j = lower_bound(va.begin(), va.end(), v[i].second) - va.begin();
        if (m - j > cnt_max) {
            sum += prea[m - cnt_max] - prea[m];
        } else {
            sum += prea[j] - prea[m];
            sum += v[i].second * (cnt_max - (m - j));
        }
        ans = max(ans, sum);
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
