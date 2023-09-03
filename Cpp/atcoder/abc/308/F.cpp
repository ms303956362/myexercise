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
    ll n, m;
    cin >> n >> m;
    multiset<ll> st;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        st.insert(x);
        ans += x;
    }
    priority_queue<pair<ll, ll>> q;
    vector<ll> l(m), d(m);
    for (int i = 0; i < m; ++i) {
        cin >> l[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> d[i];
        q.emplace(d[i], l[i]);
    }
    while (!q.empty()) {
        auto [d, l] = q.top();
        q.pop();
        auto p = st.lower_bound(l);
        if (p != st.end()) {
            ans -= d;
            st.erase(p);
        }
    }
    cout << ans << '\n';
    return 0;
}
