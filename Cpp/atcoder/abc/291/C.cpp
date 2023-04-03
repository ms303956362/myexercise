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
    map<char, pair<int, int>> dirs{
        {'R', {1, 0}},
        {'L', {-1, 0}},
        {'U', {0, 1}},
        {'D', {0, -1}},
    };
    set<pair<int, int>> vst;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0;
    vst.emplace(x, y);
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        auto [dx, dy] = dirs[s[i]];
        x += dx;
        y += dy;
        if (vst.count(make_pair(x, y))) {
            ok = false;
            break;
        } else {
            vst.emplace(x, y);
        }
    }
    cout << (ok ? "No" : "Yes") << '\n';
    return 0;
}
