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

bool is_prime[300005];
int prime[300005]; // 质数表
// C++ Version
int Eratosthenes(int n) {
  int p = 0;
  for (int i = 0; i <= n; ++i) is_prime[i] = 1;
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      prime[p++] = i;  // prime[p]是i,后置自增运算代表当前素数数量
      if ((long long)i * i <= n)
        for (int j = i * i; j <= n; j += i)
          // 因为从 2 到 i - 1 的倍数我们之前筛过了，这里直接从 i
          // 的倍数开始，提高了运行速度
          is_prime[j] = 0;  // 是i的倍数的均不是素数
    }
  }
  return p;
}

void solve() {
    ll n, m, mod = 998244353;
    cin >> n >> m;
    Eratosthenes(n + 1);
    ll ans = 0, total = 1, cnt = 1, tmp = 1;
    for (ll i = 1; i <= n; ++i) {
        total = total * (m % mod) % mod;
        if (is_prime[i] && tmp <= m) {
            tmp = tmp * i;
        }
        cnt = cnt * ((m / tmp) % mod) % mod;
        ans = (ans + total - cnt + mod) % mod;
    }
    cout << ans << endl;
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
