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
    long long a, b;
    cin >> a >> b;
    if (a == 0 && b == 0) {
        cout << 0 << '\n';
        return;
    }
    // long long l = 1, h = 1e10;
    auto f = [&](long long m) {
        return a / m + b / m + (a % m != 0) + (b % m != 0) + m - 1;
    };
    // while (l <= h) {
    //     long long m1 = l + (h - l) / 3, m2 = h - (h - l) / 3;
    //     long long f1 = f(m1), f2 = f(m2);
    //     if (f1 < f2) {
    //         h = m2 - 1;
    //     } else {
    //         l = m1 + 1;
    //     }
    // }
    // long long ans = 1e15, m0 = (l + h) / 2;
    // for (long long i = max(m0 - 10, 1LL); i <= m0 + 10; ++i) {
    //     ans = min(ans, f(i));
    // }
    long long m = sqrt(max(a, b)), ans = 1e15;
    for (long long i = max(m - 200000, 1LL); i <= m + 200000; ++i) {
        ans = min(ans, f(i));
    }
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
