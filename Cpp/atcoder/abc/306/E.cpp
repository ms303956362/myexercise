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
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(n);
    set<pair<ll, ll>> st1, st2;
    for (int i = 0; i < k; ++i) {
        st1.emplace(a[i], i);
    }
    for (int i = k; i < n; ++i) {
        st2.emplace(a[i], i);
    }
    ll sum = 0;
    while (q--) {
        ll x, y;
        cin >> x >> y;
        --x;
        if (st1.count(make_pair(a[x], x))) {
            st1.erase(make_pair(a[x], x));
            st1.emplace(y, x);
            sum += y - a[x];
            a[x] = y;
        } else {
            st2.erase(make_pair(a[x], x));
            st2.emplace(y, x);
            a[x] = y;
        }
        if (k < n) {
            auto p1 = st1.begin(), p2 = prev(st2.end());
            if (p1->first < p2->first) {
                sum += p2->first - p1->first;
                ll i1 = p1->second, i2 = p2->second;
                st1.erase(p1);
                st2.erase(p2);
                st1.emplace(a[i2], i2);
                st2.emplace(a[i1], i1);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
