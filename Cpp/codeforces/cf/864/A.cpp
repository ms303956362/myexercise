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
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<pair<int, int>> dxdy{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    auto is_valid = [&](int x, int y) {
        return 1 <= x && x <= n && 1 <= y && y <= m;
    };
    int sum1 = 0, sum2 = 0;
    for (const auto& [dx, dy] : dxdy) {
        sum1 += is_valid(x1 + dx, y1 + dy);
    }
    for (const auto& [dx, dy] : dxdy) {
        sum2 += is_valid(x2 + dx, y2 + dy);
    }
    cout << min(sum1, sum2) << '\n';
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
