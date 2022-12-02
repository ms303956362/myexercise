// IO
#include <iostream>
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

bool solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int max_num = a[0], max_idx = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            return false;
        }
        if (a[i] > max_num || (a[i] == max_num && b[i] < b[max_idx])) {
            max_num = a[i];
            max_idx = i;
        }
    }
    for (int i = max_idx, j = 0; j < n; ++j, i = (i - 1 + n) % n) {
        a[i] = min(b[i], max(a[i], a[(i + 1) % n] + 1));
    }
    int idx_beg = 0;
    while (idx_beg < n && a[idx_beg] <= a[(idx_beg + 1) % n]) {
        ++idx_beg;
    }
    if (idx_beg == n) {
        idx_beg = 0;
        int min_num = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            if (b[i] < min_num) {
                min_num = b[i];
                idx_beg = i;
            }
        }
    }
    idx_beg %= n;
    for (int i = idx_beg, j = 0; j < n; ++j, i = (i - 1 + n) % n) {
        if (a[i] < b[i]) {
            if (a[i] <= a[(i + 1) % n]) {
                a[i] = min(b[i], a[(i + 1) % n] + 1);
            }
            if (a[i] < b[i]) {
                return false;
            }
        }
    }
    return true;
}

bool solve2() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            return false;
        }
        if (a[i] < b[i] && b[i] > b[(i + 1) % n] + 1) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        if (!solve2()) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
    return 0;
}
