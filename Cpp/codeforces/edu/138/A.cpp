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
    int n, m;
    cin >> n >> m;
    vector<int> cnt_r(n), cnt_c(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        ++cnt_r[x - 1];
        ++cnt_c[y - 1];
    }
    int cr = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt_r[i] > 1) {
            cout << "NO" << endl;
            return;
        }
        cr += cnt_r[i];
    }
    if (cr >= n) {
        cout << "NO" << endl;
        return;
    }
    int cc = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt_c[i] > 1) {
            cout << "NO" << endl;
            return;
        }
        cc += cnt_c[i];
    }
    if (cc >= n) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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
