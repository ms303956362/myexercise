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

const ll maxn = 3 * 1e6 + 5;
ll is_prime[maxn], prime[maxn];
ll Eratosthenes(ll n) {
  ll p = 0;
  for (ll i = 0; i <= n; ++i) is_prime[i] = 1;
  is_prime[0] = is_prime[1] = 0;
  for (ll i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      prime[p++] = i;  // prime[p]是i,后置自增运算代表当前素数数量
      if ((long long)i * i <= n)
        for (ll j = i * i; j <= n; j += i)
          // 因为从 2 到 i - 1 的倍数我们之前筛过了，这里直接从 i
          // 的倍数开始，提高了运行速度
          is_prime[j] = 0;  // 是i的倍数的均不是素数
    }
  }
  return p;
}


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll sz = Eratosthenes(maxn);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll p, q;
        bool ok = false;
        for (int i = 0; i < min(n + 1, sz); ++i) {
            ll pp = prime[i] * prime[i];
            if (n % pp == 0) {
                p = prime[i];
                q = n / pp;
                ok = true;
                break;
            } else if (n % prime[i] == 0) {
                q = prime[i];
            }
        }
        if (!ok) {
            p = sqrt(n / q);
        }
        cout << p << " " << q << endl;
    }
    return 0;
}
