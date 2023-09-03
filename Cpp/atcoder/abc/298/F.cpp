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
    int n;
    cin >> n;
    map<ll, ll> rsum, csum;
    map<ll, set<pair<ll, ll>>> points;
    for (int i = 0; i < n; ++i) {
        ll r, c, x;
        cin >> r >> c >> x;
        rsum[r] += x;
        csum[c] += x;
        points[r].emplace(c, x);
    }
    set<pair<ll, ll>> st;
    for (const auto& [c, sum] : csum) {
        st.emplace(sum, c);
    }
    ll ans = 0;
    for (const auto& [r, v] : points) {
        vector<pair<ll, ll>> tmp;
        for (const auto& [c, x] : v) {
            ll sum = csum[c];
            tmp.emplace_back(c, sum);
            st.erase(make_pair(sum, c));
            st.emplace(sum - x, c);
            csum[c] = sum - x;
        }
        ans = max(ans, rsum[r] + st.rbegin()->first);
        for (const auto& [c, sum] : tmp) {
            st.erase(make_pair(csum[c], c));
            st.emplace(sum, c);
            csum[c] = sum;
        }
    }
    cout << ans << '\n';
    return 0;
}
