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

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll len, n1, n2;
    cin >> len >> n1 >> n2;
    map<ll, map<ll, pair<ll, ll>>> mp;
    for (ll start = 1, i = 0; i < n1; ++i) {
        ll v, l;
        cin >> v >> l;
        if (mp[v].empty()) {
            mp[v][0] = make_pair(0, 0);
        }
        ll end = start + l - 1;
        ll total = mp[v].rbegin()->second.second;
        mp[v][end] = make_pair(start, total + l);
        start += l;
    }
    auto pre_count = [&](ll num, ll x) {
        if (!mp.count(num)) {
            return 0LL;
        }
        auto& mpn = mp[num];
        auto p = mpn.lower_bound(x);
        if (p == mpn.end()) {
            return mpn.rbegin()->second.second;
        }
        if (x < p->second.first) {
            if (p == mpn.begin()) {
                return 0LL;
            }
            return prev(p)->second.second;
        }
        return p->second.second - (p->first - x);
    };
    ll ans = 0;
    for (ll start = 1, i = 0; i < n2; ++i) {
        ll v, l;
        cin >> v >> l;
        ll end = start + l - 1;
        ll cnt1 = pre_count(v, end), cnt2 = pre_count(v, start - 1);
        ans += cnt1 - cnt2;
        start += l;
    }
    cout << ans << '\n';
    return 0;
}
