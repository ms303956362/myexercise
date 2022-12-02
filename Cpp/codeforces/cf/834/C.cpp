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
    int l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    if (abs(a - b) >= x) {
        cout << 1 << endl;
        return;
    }
    if (r - b >= x && r - a >= x || a - l >= x && b - l >= x) {
        cout << 2 << endl;
        return;
    }
    if (a - l >= x && r - l >= x && r - b >= x || r - a >= x && r - l >= x && b - l >= x) {
        cout << 3 << endl;
        return;
    }
    cout << -1 << endl;
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
