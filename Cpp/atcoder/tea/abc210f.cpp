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
    ll m, n, c;
    cin >> m >> n >> c;
    vector<vector<ll>> a(m, vector<ll>(n));
    for (ll i = 0; i < m; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> mc1(m, vector<ll>(n, 0x3f3f3f3f3f3f3f3f)), mc2(m, vector<ll>(n, 0x3f3f3f3f3f3f3f3f));
    for (ll i = 0; i < m; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (i > 0) {
                mc1[i][j] = min(a[i - 1][j] - c * (i - 1 + j), mc1[i - 1][j]);
            }
            if (j > 0) {
                mc1[i][j] = min(a[i][j - 1] - c * (i + j - 1), mc1[i][j - 1]);
            }
        }
    }
    for (ll i = 0; i < m; ++i) {
        for (ll j = n - 1; j >= 0; --j) {
            if (i > 0) {
                mc2[i][j] = min(a[i - 1][j] + c * (j - i + 1), mc2[i - 1][j]);
            }
            if (j < n - 1) {
                mc2[i][j] = min(a[i][j + 1] + c * (j + 1 - i), mc2[i][j + 1]);
            }
        }
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (ll i = 0; i < m; ++i) {
        for (ll j = 0; j < n; ++j) {
            ans = min({ans, a[i][j] + c * (i + j) + mc1[i][j], a[i][j] + c * (i - j) + mc2[i][j]});
        }
    }
    cout << ans << endl;
    return 0;
}
