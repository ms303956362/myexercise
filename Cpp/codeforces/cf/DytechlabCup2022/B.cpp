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
#include <random>

using namespace std;

using ll = long long;

void solve(ll l, ll r) {
    ll s = sqrt(l), e = sqrt(r);
    if (s == e) {
        ll ans = 0;
        if (l <= s * s && s * s <= r) {
            ++ans;
        }
        if (l <= s * s + s && s * s + s <= r) {
            ++ans;
        }
        if (l <= s * s + 2 * s && s * s + 2 * s <= r) {
            ++ans;
        }
        cout << ans << endl;
        return;
    }
    ll ans = (e - s - 1) * 3;
    if (l <= s * s) {
        ans += 3;
    } else if (l <= s * s + s) {
        ans += 2;
    } else if (l <= s * s + 2 * s) {
        ++ans;
    }
    if (r >= e * e + 2 * e) {
        ans += 3;
    } else if (r >= e * e + e) {
        ans += 2;
    } else if (r >= e * e) {
        ++ans;
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        solve(l, r);
    }
    return 0;
}
