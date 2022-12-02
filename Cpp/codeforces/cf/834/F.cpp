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
    int n, p;
    cin >> n >> p;
    set<int> st;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        st.insert(a[i]);
    }
    set<int> vst;
    for (int i = 0; i < n; ++i) {
        if (a[i] < a[n - 1]) {
            vst.insert(a[i]);
        }
    }
    if ((int)vst.size() == a[n - 1]) {
        int num = p - 1;
        while (num > a[n - 1] && st.count(num)) {
            --num;
        }
        cout << num - a[n - 1] << endl;
    } else {
        int ans = p - a[n - 1];
        vst.insert(0);
        int i = n - 2;
        while (i >= 0 && a[i] == p - 1) {
            --i;
        }
        if (i < 0 && 1 < a[n - 1]) {
            vst.insert(1);
        } else if (a[i] + 1 < a[n - 1]) {
            vst.insert(a[i] + 1);
        }
        if ((int)vst.size() == a[n - 1]) {
            cout << ans << endl;
        } else {
            int num = a[n - 1] - 1;
            while (vst.count(num)) {
                --num;
            }
            cout << ans + num << endl;
        }
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
