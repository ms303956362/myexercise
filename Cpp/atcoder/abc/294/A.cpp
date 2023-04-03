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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(n), c(m), d(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> c[i] >> d[i];
    }
    auto cnt = [&](double rr) {
        double r = rr / 100;
        vector<double> v;
        for (int i = 0; i < m; ++i) {
            v.push_back(r * (c[i] + d[i]) - c[i]);
        }
        sort(v.begin(), v.end());
        ll total = 0;
        for (int i = 0; i < n; ++i) {
            double val = a[i] - r * (a[i] + b[i]);
            total += upper_bound(v.begin(), v.end(),  val) - v.begin();
        }
        return total;
    };
    double l = 0, h = 100;
    while (h - l > 1e-11) {
        double r = (l + h) / 2;
        ll cc = cnt(r);
        if (cc < k) {
            h = r;
        } else {
            l = r;
        }
    }
    cout << fixed << setprecision(16) << (l + h) / 2 << '\n';
    return 0;
}
