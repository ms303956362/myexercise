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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << -1 << '\n';
        return;
    }
    sort(a.begin(), a.end());
    set<int> st;
    for (int i = 1; i < n; ++i) {
        st.insert(a[i] - a[i - 1]);
    }
    if (st.size() > 2) {
        cout << 0 << '\n';
        return;
    }
    if (st.size() == 1) {
        if (*st.begin() == 0) {
            cout << 1 << '\n';
            cout << *a.begin() << '\n';
        } else if (n > 2 || *st.begin() % 2 != 0) {
            cout << 2 << '\n';
            cout << *a.begin() - *st.begin() << ' ' << *a.rbegin() + *st.begin() << '\n';
        } else {
            cout << 3 << '\n';
            cout << *a.begin() - *st.begin() << ' ' << (*a.begin() + *a.rbegin()) / 2 << ' ' << *a.rbegin() + *st.begin() << '\n';
        }
        return;
    }
    int d1 = *st.begin(), d2 = *next(st.begin());
    if (d2 != d1 * 2) {
        cout << 0 << '\n';
        return;
    }
    int num = 0, cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] == d2) {
            num = (a[i] + a[i - 1]) / 2;
            ++cnt;
        }
    }
    if (cnt == 1) {
        cout << 1 << '\n';
        cout << num << '\n';
        return;
    }
    cout << 0 << '\n';
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
