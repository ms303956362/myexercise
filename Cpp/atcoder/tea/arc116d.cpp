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

const int mod = 998244353;
const ll MAXN = 5005;
ll inv[MAXN + 200];
ll C[MAXN];
void getinv()
{
    inv[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
}
void getfac(ll n)
{
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        C[i] = C[i - 1] * (n - i + 1) % mod * inv[i] % mod;
    }

}

int dp[15][5005];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    getinv();
    getfac(n);
    int base = 1;
    dp[0][0] = 1;
    for (int i = 1; i <= 13; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= n && k * base <= j; k += 2) {
                dp[i][j] = (dp[i][j] + C[k] * dp[i - 1][j - k * base] % mod) % mod;
            }
        }
        base *= 2;
    }
    cout << dp[13][m] << endl;
    return 0;
}
