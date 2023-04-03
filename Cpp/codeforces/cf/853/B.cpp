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
    string s;
    cin >> s;
    int i = 0, j = n - 1;
    while (i < j && s[i] == s[j]) {
        ++i;
        --j;
    }
    if (i >= j) {
        cout << "Yes" << '\n';
        return;
    }
    int l = i;
    while (i < j && s[i] != s[j]) {
        ++i;
        --j;
    }
    if (i >= j) {
        cout << "Yes" << '\n';
        return;
    }
    int r1 = i - 1, r2 = j;
    auto check = [](int n, const string& s) {
        int i = 0, j = n - 1;
        while (i < j && s[i] == s[j]) {
            ++i;
            --j;
        }
        if (i >= j) {
            return true;
        }
        return false;
    };
    for (int i = l; i <= r1; ++i) {
        if (s[i] == '0') {
            s[i] = '1';
        } else {
            s[i] = '0';
        }
    }
    if (check(n, s)) {
        cout << "Yes" << '\n';
        return;
    }
    for (int i = l; i <= r1; ++i) {
        if (s[i] == '0') {
            s[i] = '1';
        } else {
            s[i] = '0';
        }
    }
    for (int i = l; i <= r2; ++i) {
        if (s[i] == '0') {
            s[i] = '1';
        } else {
            s[i] = '0';
        }
    }
    if (check(n, s)) {
        cout << "Yes" << '\n';
        return;
    }
    cout << "No" << '\n';
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
