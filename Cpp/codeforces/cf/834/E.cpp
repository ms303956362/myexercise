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
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    auto work = [&](const vector<int>& stones) {
        ll i = 0, j = 0;
        ll hh = h;
        while (i < n) {
            if (hh > a[i]) {
                hh += a[i] / 2;
                ++i;
            } else if (j < 3) {
                hh *= stones[j];
                ++j;
            } else {
                break;
            }
        }
        return i;
    };
    cout << max({work({2, 2, 3}), work({2, 3, 2}), work({3, 2, 2})}) << endl;
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
