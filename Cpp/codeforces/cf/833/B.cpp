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

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        vector<ll> cnt(10);
        ll max_cnt = 0, diff = 0;
        for (ll j = i; j < n && j <= i + 100; ++j) {
            if (cnt[s[j] - '0'] == 0) {
                ++diff;
            }
            ++cnt[s[j] - '0'];
            max_cnt = max(max_cnt, cnt[s[j] - '0']);
            if (max_cnt <= diff) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
