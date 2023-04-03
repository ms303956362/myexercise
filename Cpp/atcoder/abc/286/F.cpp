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

ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = exgcd(b, a % b, x, y);
  ll t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}


ll CRT(int k, ll* a, ll* r) {
  ll n = 1, ans = 0;
  for (int i = 1; i <= k; i++) n = n * r[i];
  for (int i = 1; i <= k; i++) {
    ll m = n / r[i], b, y;
    exgcd(m, r[i], b, y);  // b * m mod r[i] = 1
    ans = (ans + a[i] * m * b % n) % n;
  }
  return (ans % n + n) % n;
}


ll r[10] = {0, 4, 5, 7, 9, 11, 13, 17, 19, 23}, a[10];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << 108 << endl;
    vector<int> aa{2, 3, 4, 1, 6, 7, 8, 9, 5, 11, 12, 13, 14, 15, 16, 10, 18, 19, 20, 21, 22, 23, 24, 25, 17, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 26, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 37, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 50, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 67, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 86};
    for (const auto& x : aa) {
        cout << x << " ";
    }
    cout << endl;
    vector<int> b(108);
    for (int i = 0; i < 108; ++i) {
        cin >> b[i];
    }
    int i = -1;
    for (int j = 1; j <= 9; ++j) {
        i += r[j];
        a[j] = b[i] - aa[i];
    }
    cout << CRT(9, a, r) + 1 << endl;
    return 0;
}
