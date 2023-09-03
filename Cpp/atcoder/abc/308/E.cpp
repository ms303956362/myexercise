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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<vector<ll>> cntm(n, vector<ll>(3)), cntx(n, vector<ll>(3));
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cntm[i] = cntm[i - 1];
        }
        if (s[i] == 'M') {
            ++cntm[i][a[i]];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (i < n - 1) {
            cntx[i] = cntx[i + 1];
        }
        if (s[i] == 'X') {
            ++cntx[i][a[i]];
        }
    }
    auto mex = [](int a, int b, int c) {
        vector<int> cnt(3);
        ++cnt[a];
        ++cnt[b];
        ++cnt[c];
        for (int i = 0; i < 3; ++i) {
            if (cnt[i] == 0) {
                return i * 1LL;
            }
        }
        return 3LL;
    };
    vector<vector<vector<ll>>> mex_tab(3, vector<vector<ll>>(3, vector<ll>(3)));
    for (int a = 0; a < 3; ++a) {
        for (int b = 0; b < 3; ++b) {
            for (int c = 0; c < 3; ++c) {
                mex_tab[a][b][c] = mex(a, b, c);
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (s[i] == 'E') {
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    ll m = mex_tab[x][a[i]][y];
                    ans += m * cntm[i - 1][x] * cntx[i + 1][y];
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
