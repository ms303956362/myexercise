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
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 != 0) {
        cout << -1 << endl;
        return;
    }
    if (sum == 0) {
        cout << n << endl;
        for (int i = 1; i <= n; ++i) {
            cout << i << " " << i << endl;
        }
    } else if (sum > 0) {
        int k = 0;
        vector<bool> ispair(n);
        int cnt = n;
        for (int j = 0; j < sum / 2; ++j) {
            while (k + 1 < n && a[k + 1] != 1) {
                ++k;
            }
            if (k + 1 < n) {
                ispair[k] = true;
                k += 2;
                --cnt;
            } else {
                cout << -1 << endl;
                return;
            }
        }
        cout << cnt << endl;
        for (int i = 0; i < n; ) {
            if (ispair[i]) {
                cout << i + 1 << " " << i + 2 << endl;
                i += 2;
            } else {
                cout << i + 1 << " " << i + 1 << endl;
                ++i;
            }
        }
    } else {
        int k = 0;
        vector<bool> ispair(n);
        int cnt = n;
        for (int j = 0; j < -sum / 2; ++j) {
            while (k + 1 < n && a[k + 1] != -1) {
                ++k;
            }
            if (k + 1 < n) {
                ispair[k] = true;
                k += 2;
                --cnt;
            } else {
                cout << -1 << endl;
                return;
            }
        }
        cout << cnt << endl;
        for (int i = 0; i < n; ) {
            if (ispair[i]) {
                cout << i + 1 << " " << i + 2 << endl;
                i += 2;
            } else {
                cout << i + 1 << " " << i + 1 << endl;
                ++i;
            }
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
