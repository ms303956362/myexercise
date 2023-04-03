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
const ll maxn = 105, mod = 1e9 + 7;

ll C[maxn + 5][maxn + 5];
ll P[maxn];

void get_P() {
    P[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        P[i] = (P[i - 1] * 2) % mod;
    }
}

void get_C()
{
    C[0][0] = 1;
    for(int i=1;i<=maxn;i++)
    {
        C[i][0] = 1;
        for(int j=1;j<=i;j++) {
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
}

void solve() {
    ll n, i, j, x, y;
    cin >> n >> i >> j >> x >> y;
    if (x < y) {
        ll ii = n + 1 - j, jj = n + 1 - i;
        i = ii;
        j = jj;
        swap(x, y);
    }
    auto calc = [&]() {
        if (n - x - 1 < 0 || n - x > j - i - 1 || n - y - 1 < j - i - 1 || y - 1 < n - j - 1) {
            return 0LL;
        }
        return ((((P[n - x - 1]) * C[n - y - 1 - (n - x)][j - i - 1 - (n - x)]) % mod) * C[y - 1][n - j]) % mod;
    };
    cout << calc() << endl;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    get_C();
    get_P();
    while (t--) {
        solve();
    }
    return 0;
}
