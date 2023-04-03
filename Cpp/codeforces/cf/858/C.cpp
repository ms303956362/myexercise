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
    vector<int> p(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> p[i];
    }
    if (n == 1) {
        cout << abs(p[0] - p[1]) << '\n';
        return;
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    if (n == 2) {
        ll sum = 0;
        for (int i = 0; i < 2 * n; ++i) {
            sum += abs(p[i] - 2);
        }
        ans = min(ans, sum);
    }
    if (n % 2 == 0) {
        ll sum = 0, min_sum = 0x3f3f3f3f3f3f3f3f;
        for (int i = 0; i < 2 * n; ++i) {
            sum += abs(p[i] + 1);
        }
        for (int i = 0; i < 2 * n; ++i) {
            sum -= abs(p[i] + 1);
            sum += abs(p[i] - n);
            min_sum = min(min_sum, sum);
            sum -= abs(p[i] - n);
            sum += abs(p[i] + 1);
        }
        ans = min(ans, min_sum);
    }
    ll sum = 0;
    for (int i = 0; i < 2 * n; ++i) {
        sum += abs(p[i]);
    }
    ans = min(ans, sum);
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
