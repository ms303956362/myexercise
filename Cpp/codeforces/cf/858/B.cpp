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
    int cnt0 = 0, max_num = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 0) {
            ++cnt0;
        }
        max_num = max(max_num, x);
    }
    if (cnt0 <= (n + 1) / 2) {
        cout << 0 << '\n';
    } else if (max_num > 1) {
        cout << 1 << '\n';
    } else {
        cout << max_num + 1 << '\n';
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
