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
    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    b[0] = a[0];
    b[n] = a[n - 1];
    for (int i = 1; i < n; ++i) {
        int g = __gcd(a[i], a[i - 1]);
        b[i] = g * (a[i] / g) * (a[i - 1] / g);
    }
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = __gcd(b[i], b[i + 1]);
    }
    cout << (a == c ? "YES" : "NO") << endl;
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
