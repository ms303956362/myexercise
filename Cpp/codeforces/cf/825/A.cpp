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
    vector<int> a(n), b(n);
    int cnt1a = 0, cnt1b = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i]) {
            ++cnt1a;
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i]) {
            ++cnt1b;
        }
    }
    int diff = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            ++diff;
        }
    }
    cout << min(diff, abs(cnt1b - cnt1a) + 1) << endl;
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
