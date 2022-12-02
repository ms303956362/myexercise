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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> c(n, vector<int>(n)), pre(n + 1, vector<int>(n + 1));
    auto check = [&](int m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                c[i][j] = (a[i][j] >= m);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                pre[i][j] = c[i][j] + pre[i + 1][j] + pre[i][j + 1] - pre[i + 1][j + 1];
            }
        }
        for (int i = 0; i <= n - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {
                if (pre[i][j] - pre[i][j + k] - pre[i + k][j] + pre[i + k][j + k] < k * k / 2 + 1) {
                    return false;
                }
            }
        }
        return true;
    };
    int l = 0, h = 1e9 + 5, ans = 0;
    while (l <= h) {
        int m = (l + h) / 2;
        if (check(m)) {
            ans = m;
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
