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

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    reverse(b.begin(), b.end());
    int l = n, r = -1, val = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            val = a[i];
            l = min(l, i);
            r = max(r, i);
        }
    }
    if (l > r) {
        cout << "Yes" << endl;
        for (int i = 0; i < n; ++i) {
            cout << b[i] << " ";
        }
        cout << endl;
        return 0;
    }
    int cntl = 0, cntr = 0;
    for (int i = 0; i < n && b[i] != val && a[i] != val; ++i) {
        ++cntl;
    }
    for (int i = n - 1; i >= 0 && b[i] != val && a[i] != val; --i) {
        ++cntr;
    }
    if (cntl + cntr < l - r + 1) {
        cout << "No" << endl;
        return 0;
    }
    int i = 0, j = n - 1;
    for (int k = l; k <= r; ++k) {
        if (cntl > 0) {
            swap(b[i], b[k]);
            ++i;
            --cntl;
        } else if (cntr > 0) {
            swap(b[j], b[k]);
            --j;
            --cntr;
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}
