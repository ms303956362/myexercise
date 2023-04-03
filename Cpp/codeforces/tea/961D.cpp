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

bool check(int n, vector<ll>& x, vector<ll>& y) {
    if (n < 5) {
        return true;
    }
    vector<bool> on_line(n, false);
    auto count_points = [&](ll a, ll b, ll c) {
        on_line = vector<bool>(n, false);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a * x[i] + b * y[i] + c == 0) {
                on_line[i] = true;
                ++cnt;
            }
        }
        return cnt;
    };
    auto check_one_line = [&]() -> bool {
        vector<ll> xx, yy;
        for (int i = 0; i < n; ++i) {
            if (!on_line[i]) {
                xx.push_back(x[i]);
                yy.push_back(y[i]);
            }
        }
        if (xx.size() < 3) {
            return true;
        }
        ll a = yy[0] - yy[1], b = xx[1] - xx[0], c = xx[0] * yy[1] - xx[1] * yy[0];
        int l = xx.size();
        for (int i = 0; i < l; ++i) {
            if (a * xx[i] + b * yy[i] + c != 0) {
                return false;
            }
        }
        return true;
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            ll a = y[i] - y[j], b = x[j] - x[i], c = x[i] * y[j] - x[j] * y[i];
            if (count_points(a, b, c) >= 3) {
                return check_one_line();
            }
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    if (check(n, x, y)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
