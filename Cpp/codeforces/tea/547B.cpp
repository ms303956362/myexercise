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
    stack<int> st;
    vector<int> l(n, -1), r(n, n);
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            l[i] = st.top();
        }
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            r[i] = st.top();
        }
        st.push(i);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int len = r[i] - l[i] - 1;
        ans[len - 1] = max(ans[len - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
