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
int a[262144];

int mergeSort(int l, int h, int n) {
    if (n == 0) {
        return 0;
    }
    int m = h - l + 1;
    int max_num = *max_element(a + l, a + h + 1);
    bool in_front = true;
    for (int i = l + m / 2; i <= h; ++i) {
        if (a[i] == max_num) {
            in_front = false;
            break;
        }
    }
    if (in_front && *min_element(a + l, a + l + m / 2) < *max_element(a + l + m / 2, a + l + m)) {
        return -1;
    }
    if (!in_front && *max_element(a + l, a + l + m / 2) > *min_element(a + l + m / 2, a + l + m)) {
        return -1;
    }
    int ans = in_front ? 1 : 0;
    int ansl = mergeSort(l, l + m / 2 - 1, n - 1);
    if (ansl == -1) {
        return -1;
    }
    ans += ansl;
    int ansr = mergeSort(l + m / 2, h, n - 1);
    if (ansr == -1) {
        return -1;
    }
    ans += ansr;
    return ans;
}

void solve() {
    int m;
    cin >> m;
    int n = 0, p = 1;
    while (p < m) {
        ++n;
        p *= 2;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    cout << mergeSort(0, m - 1, n) << endl;
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
