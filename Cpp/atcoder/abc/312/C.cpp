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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l = 1, h = 1e9 + 7;
    auto check = [&](int t) {
        int cnts = 0, cntb = 0;
        for (int i = 0; i < n && a[i] <= t; ++i) {
            ++cnts;
        }
        for (int i = m - 1; i >= 0 && b[i] >= t; --i) {
            ++cntb;
        }
        return cnts >= cntb;
    };
    int ans = 1;
    while (l <= h) {
        int t = (l + h) / 2;
        if (check(t)) {
            ans = t;
            h = t - 1;
        } else {
            l = t + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
