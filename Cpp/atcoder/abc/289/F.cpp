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

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int sx, sy, tx, ty, a, b, c, d;
    cin >> sx >> sy >> tx >> ty >> a >> b >> c >> d;
    if ((sx - tx) % 2 != 0 || (sy - ty) % 2 != 0) {
        cout << "No" << '\n';
        return 0;
    }
    vector<pair<int, int>> ans;
    if (sx != tx && a == b) {
        sx = 2 * a - sx;
        sy = 2 * c - sy;
        ans.emplace_back(a, c);
    }
    if (sy != ty && c == d) {
        sx = 2 * a - sx;
        sy = 2 * c - sy;
        ans.emplace_back(a, c);
    }
    if ((sx != tx && a == b) || (sy != ty && c == d)) {
        cout << "No" << '\n';
        return 0;
    }
    while (sx < tx) {
        sx += 2;
        ans.emplace_back(a, c);
        ans.emplace_back(a + 1, c);
    }
    while (sx > tx) {
        sx -= 2;
        ans.emplace_back(b, d);
        ans.emplace_back(b - 1, d);
    }
    while (sy < ty) {
        sy += 2;
        ans.emplace_back(a, c);
        ans.emplace_back(a, c + 1);
    }
    while (sy > ty) {
        sy -= 2;
        ans.emplace_back(b, d);
        ans.emplace_back(b, d - 1);
    }
    cout << "Yes" << '\n';
    for (const auto& [x, y] : ans) {
        cout << x << " " << y << '\n';
    }
    return 0;
}
