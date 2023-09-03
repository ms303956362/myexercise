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
#include <numeric>
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
    string s, t;
    cin >> s >> t;
    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            ++d1;
        }
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            ++d2;
        }
    }
    if (d1 == 0) {
        cout << 0 << '\n';
        return;
    }
    if (d2 == 0) {
        cout << 2 << '\n';
        return;
    }
    int t1 = 2 * d1 - d1 % 2, t2 = 2 * d2 - 1 + d2 % 2;
    cout << min(t1, t2) << '\n';
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
