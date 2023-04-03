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
    string s;
    cin >> s;
    int n = s.size();
    map<ll, ll> cnt;
    ll x = 0;
    cnt[x] = 1;
    ll ans = 0;
    for (ll i = n - 1; i >= 0; --i) {
        ll num = s[i] - '0';
        x ^= (1LL << num);
        ans += cnt[x];
        ++cnt[x];
    }
    cout << ans << '\n';
    return 0;
}
