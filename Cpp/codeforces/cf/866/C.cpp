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

int MEX(int n, vector<int>& a) {
    vector<bool> has(n);
    for (const auto& num : a) {
        if (0 <= num && num < n) {
            has[num] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!has[i]) {
            return i;
        }
    }
    return n;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int m = MEX(n, a);
    if (m == 0) {
        cout << "Yes" << '\n';
        return;
    }
    int l = 0, r = n - 1;
    while (l < n && a[l] != m + 1) {
        ++l;
    }
    while (r >= 0 && a[r] != m + 1) {
        --r;
    }
    if (l > r) {
        int cnt = 0;
        for (const auto& num : a) {
            if (0 <= num && num < m) {
                ++cnt;
            }
        }
        if (cnt > m || cnt < n) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
        return;
    }
    for (int i = l; i <= r; ++i) {
        a[i] = m;
    }
    cout << (MEX(n, a) == m + 1 ? "Yes" : "No") << '\n';
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
