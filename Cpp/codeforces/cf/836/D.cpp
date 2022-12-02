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
    vector<int> a(n);
    a[0] = 3 * n;
    a[n - 1] = 5 * n;
    int i = 1, j = n - 2, k = 1;
    while (i < j) {
        a[i] = 4 * n - k;
        a[j] = 4 * n + k;
        ++k;
        ++i;
        --j;
    }
    if (i == j) {
        a[i] = 4 * n;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
    }
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
