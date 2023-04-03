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
    ll n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> cnt(n + 1), g(n + 1);
    ll ans = 0;
    for (ll i = n - 1; i >= 0; --i) {
        ++cnt[a[i]];
        g[i] = g[i + 1] + n - i - cnt[a[i]];
        ans += g[i];
        // cout << g[i] << " ";
    }
    int i = n / 2, j = (n + 1) / 2;
    vector<ll> cnt2(n + 1);
    while (i > 0 && j < n) {
        ++cnt2[a[i]];
        if (j != i) {
            ++cnt2[a[j]];
        }
        ans -= j - i + 1 - cnt2[a[j]];
        --i;
        ++j;
    }
    cout << ans << '\n';
    return 0;
}
