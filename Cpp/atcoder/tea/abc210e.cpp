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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < m && n > 1; ++i) {
        ll a = v[i].second % n, c = v[i].first;
        if (a == 0) {
            continue;
        }
        ll g = __gcd(n, a);
        ans += (n / g - 1) * g * c;
        n = g;
    }
    cout << (n > 1 ? -1 : ans) << endl;
    return 0;
}
