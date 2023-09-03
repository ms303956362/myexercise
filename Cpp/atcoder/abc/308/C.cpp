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
#include <numeric>
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
    vector<tuple<ll, ll, ll>> v;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        v.emplace_back(x, x + y, i + 1);
    }
    sort(v.begin(), v.end(), [](auto l, auto r) {
        auto [al, sl, idl] = l;
        auto [ar, sr, idr] = r;
        return al * sr > ar * sl || (al * sr == ar * sl && idl < idr);
    });
    for (int i = 0; i < n; ++i) {
        cout << get<2>(v[i]) << ' ';
    }
    cout << '\n';
    return 0;
}
