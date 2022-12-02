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
    ll n, m;
    cin >> n >> m;
    ll cnt5 = 0, cnt2 = 0;
    ll tmp = n;
    while (tmp % 5 == 0) {
        ++cnt5;
        tmp /= 5;
    }
    while (tmp % 2 == 0) {
        ++cnt2;
        tmp /= 2;
    }
    ll ans = 1;
    if (cnt5 > cnt2) {
        for (int i = 0; i < cnt5 - cnt2 && ans * 2 <= m; ++i) {
            ans *= 2;
        }
    } else if (cnt5 < cnt2) {
        for (int i = 0; i < cnt2 - cnt5 && ans * 5 <= m; ++i) {
            ans *= 5;
        }
    }
    while (ans * 10 <= m) {
        ans *= 10;
    }
    ll k = m / ans;
    cout << n * k * ans << endl;
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
