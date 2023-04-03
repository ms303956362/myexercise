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
    stack<int> stg, stl;
    vector<int> rightg(n, n), rightl(n, n), leftg(n, -1), leftl(n, -1);
    for (int i = 0; i < n; ++i) {
        while (!stg.empty() && a[stg.top()] < a[i]) {
            stg.pop();
        }
        if (!stg.empty()) {
            leftg[i] = stg.top();
        }
        stg.push(i);
        while (!stl.empty() && a[stl.top()] > a[i]) {
            stl.pop();
        }
        if (!stl.empty()) {
            leftl[i] = stl.top();
        }
        stl.push(i);
    }
    while (!stg.empty()) {
        stg.pop();
    }
    while (!stl.empty()) {
        stl.pop();
    }
    for (int i = n - 1; i >= 0; --i) {
        while (!stg.empty() && a[stg.top()] < a[i]) {
            stg.pop();
        }
        if (!stg.empty()) {
            rightg[i] = stg.top();
        }
        stg.push(i);
        while (!stl.empty() && a[stl.top()] > a[i]) {
            stl.pop();
        }
        if (!stl.empty()) {
            rightl[i] = stl.top();
        }
        stl.push(i);
    }
    vector<int> min_l(n + 1, -1);
    for (int i = n - 1; i >= 0; --i) {
        min_l[i] = max(min_l[i + 1], min(leftg[i], leftl[i]));
    }
    int ansl = -1, ansr = -1;
    for (int i = 0; i < n; ++i) {
        int ri = max(rightg[i], rightl[i]);
        if (ri != n && i <= min_l[ri]) {
            for (int j = ri; j < n; ++j) {
                if (leftg[j] != -1 && leftl[j] != -1 && min(leftg[j], leftl[j]) >= i) {
                    ansl = i + 1;
                    ansr = j + 1;
                    break;
                }
            }
            break;
        }
    }
    if (ansl == -1 && ansr == -1) {
        cout << -1 << '\n';
    } else {
        cout << ansl << ' ' << ansr << '\n';
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
