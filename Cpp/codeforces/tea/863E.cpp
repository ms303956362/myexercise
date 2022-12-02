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
    int n;
    cin >> n;
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        v.emplace_back(l, r, i + 1);
    }
    sort(v.begin(), v.end(), [](const auto& lv, const auto& rv) {
        auto [ll, lr, li] = lv;
        auto [rl, rr, ri] = rv;
        return ll < rl || (ll == rl && lr > rr);
    });
    for (int i = 1; i < n; ++i) {
        auto [l1, r1, i1] = v[i - 1];
        auto [l2, r2, i2] = v[i];
        if (r1 >= r2) {
            cout << i2 << endl;
            return 0;
        }
    }
    for (int i = 1; i < n - 1; ++i) {
        auto [l1, r1, i1] = v[i - 1];
        auto [l2, r2, i2] = v[i];
        auto [l3, r3, i3] = v[i + 1];
        if (r1 + 1 >= l3) {
            cout << i2 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
