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
    int t;
    cin >> t;
    cout << fixed << setprecision(12);
    double eps = 1e-9;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n), t(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> t[i];
        }
        auto f = [&](double x0) {
            double ans = 0;
            for (int i = 0; i < n; ++i) {
                ans = max(ans, t[i] + abs(x[i] - x0));
            }
            return ans;
        };
        double l = *min_element(x.begin(), x.end()), h = *max_element(x.begin(), x.end());
        while (abs(l - h) > eps) {
            double m1 = l + (h - l) / 3, m2 = h - (h - l) / 3;
            if (f(m1) >= f(m2)) {
                l = m1;
            } else {
                h = m2;
            }
        }
        cout << (l + h) / 2 << endl;
        // double l = *max_element(t.begin(), t.end()), h = l + *max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end()) + 1;
        // auto check = [&](double m) {
        //     double lb = 1e-9, hb = 1e9;
        //     for (int i = 0; i < n; ++i) {
        //         lb = max(lb, x[i] + t[i] - m);
        //         hb = min(hb, x[i] - t[i] + m);
        //     }
        //     return hb - lb > eps;
        // };
        // while (abs(l - h) > eps) {
        //     double m = (l + h) / 2;
        //     if (check(m)) {
        //         h = m;
        //     } else {
        //         l = m;
        //     }
        // }
        // double m = (l + h) / 2;
        // double lb = 1e-9, hb = 1e9;
        // for (int i = 0; i < n; ++i) {
        //     lb = max(lb, x[i] + t[i] - m);
        //     hb = min(hb, x[i] - t[i] + m);
        // }
        // cout << (lb + hb) / 2 << endl;
    }
    return 0;
}
