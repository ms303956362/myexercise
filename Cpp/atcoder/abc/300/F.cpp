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
    ll n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<ll> idx;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'x') {
            idx.push_back(i);
        }
    }
    ll l = idx.size();
    ll ans = 0;
    for (int i = 0; i < l; ++i) {
        int j = (i + (k - 1) % l) % l;
        ll start = idx[i], end = idx[j];
        ll pre = (i == 0 ? (start + 1) : (start - idx[i - 1])), suf = (j == l - 1 ? (n - idx[j]) : (idx[j + 1] - idx[j]));
        if (start <= end) {
            ans = max(ans, n * (k / l) + pre + suf + end - start - 1);
        } else {
            ans = max(ans, n * (k / l) + pre + suf + n - start - 1 + end);
        }
    }
    cout << ans << '\n';
    return 0;
}
