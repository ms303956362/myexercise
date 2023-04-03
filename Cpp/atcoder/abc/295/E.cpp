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

ll pow(ll x, ll n, ll mod) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = (ret * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

ll mod = 998244353;
const ll N = 2005;
long long C[N][N];

void get_C(int maxn)
{
    C[0][0] = 1;
    for(int i=1;i<=maxn;i++)
    {
        C[i][0] = 1;
        for(int j=1;j<=i;j++)
            // C[i][j] = C[i-1][j]+C[i-1][j-1];
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    get_C(n + 1);
    vector<int> a;
    ll c0 = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (x > 0) {
            a.push_back(x);
        } else {
            ++c0;
        }
    }
    ll numi = 0, den = pow(m, c0, mod);
    for (ll num = 1; num <= m; ++num) {
        ll ks = 0, keq = 0;
        for (const auto& x : a) {
            if (x < num) {
                ++ks;
            }
            if (x == num) {
                ++keq;
            }
        }
        ll cnt = 0;
        for (ll cs = 0; cs < k - ks; ++cs) {
            for (ll ceq = max(k - (ks + cs + keq), 0LL); ceq <= c0 - cs; ++ceq) {
                ll cg = c0 - cs - ceq;
                cnt += ((C[c0][cs] * pow(num - 1, cs, mod)) % mod 
                * (C[c0 - cs][cg] * pow(m - num, cg, mod)) % mod) % mod;
            }
        }
        numi = (numi + num * cnt % mod) % mod;
    }
    cout << (numi * pow(den, mod - 2, mod)) % mod << '\n';
    return 0;
}
