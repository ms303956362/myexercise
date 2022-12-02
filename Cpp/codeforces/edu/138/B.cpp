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
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ans += x;
    }
    ll max_b = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        max_b = max(max_b, x);
        ans += x;
    }
    ans -= max_b;
    cout << ans << endl;
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
