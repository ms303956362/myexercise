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
    vector<vector<int>> ans(n, vector<int>(n));
    int x = 0, y = 0, num = 1, delta = n * n - 1, sgn = 1, dir = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[x][y] = num;
            num += delta * sgn;
            sgn = -sgn;
            --delta;
            if (0 <= x + dir && x + dir < n) {
                x += dir;
            }
        }
        ++y;
        dir = -dir;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
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
