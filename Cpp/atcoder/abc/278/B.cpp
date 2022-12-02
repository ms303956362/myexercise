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
    int h, m;
    cin >> h >> m;
    auto is_valid = [](int h, int m) {
        return 0 <= h && h <= 23 && 0 <= m && m <= 59;
    };
    auto next_time = [](int h, int m) {
        if (m < 59) {
            return make_pair(h, m + 1);
        }
        if (h < 23) {
            return make_pair(h + 1, 0);
        }
        return make_pair(0, 0);
    };
    while (!is_valid((h / 10) * 10 + m / 10, (h % 10) * 10 + m % 10)) {
        auto [hh, mm] = next_time(h, m);
        h = hh;
        m = mm;
    }
    cout << h << " " << m << endl;
    return 0;
}
