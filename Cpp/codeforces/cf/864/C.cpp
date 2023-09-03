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
    cout << "? " << 1 << " " << 1 << endl;
    int d1;
    cin >> d1;
    if (d1 + 1 <= n) {
        cout << "? " << d1 + 1 << " " << 1 << endl;
        int d2;
        cin >> d2;
        if (d2 < d1) {
            cout << "! " << d1 + 1 << " " << d2 + 1 << endl;
            return;
        }
    }
    if (d1 + 1 <= m) {
        cout << "? " << 1 << " " << d1 + 1 << endl;
        int d3;
        cin >> d3;
        cout << "! " << d3 + 1 << " " << d1 + 1 << endl;
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
