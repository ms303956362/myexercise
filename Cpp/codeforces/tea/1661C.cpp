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
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    ll mx = *max_element(h.begin(), h.end());
    auto calc = [&](ll num) {
        ll sum = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if ((num - h[i]) % 2 == 1) {
                ++cnt;
            }
            sum += num - h[i];
        }
        return max(2 * (cnt - 1) + 1, sum / 3 * 2 + sum % 3);
    };
    cout << min({calc(mx), calc(mx + 1), calc(mx + 2)}) << '\n';
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
