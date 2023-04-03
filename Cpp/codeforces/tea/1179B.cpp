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
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << i + 1 << " " << j + 1 << '\n';
            cout << n - i << " " << m - j << '\n';
        }
    }
    if (n % 2) {
        for (int j = 0; j < m / 2; ++j) {
            cout << n / 2 + 1 << " " << j + 1 << '\n';
            cout << n / 2 + 1 << " " << m - j << '\n';
        }
        if (m % 2) {
            cout << n / 2 + 1 << " " << m / 2 + 1 << '\n';
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
