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

void solve() {
    int n, m, w;
    cin >> n >> m >> w;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    int l = 0, h = *max_element(a.begin(), a.end()) + m + 5;
    auto check = [&](int target) {
        vector<ll> diff(n);
        ll k = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            k += diff[i];
            ll curr = a[i] + k;
            if (target <= curr) {
                continue;
            }
            cnt += (ll)(target - curr);
            if (cnt > m) {
                return false;
            }
            if (i + w < n) {
                diff[i + w] -= (ll)(target - curr);
            }
            k = (ll)(target - a[i]);
        }
        return cnt <= m;
    };
    while (l <= h) {
        int mid = (l + h) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}