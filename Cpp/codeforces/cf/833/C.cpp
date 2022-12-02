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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> pre(n);
    int i = 0;
    ll ans = 0;
    while (i < n && a[i] != 0) {
        if (i > 0) {
            pre[i] = pre[i - 1] + a[i];
        } else {
            pre[i] = a[i];
        }
        if (pre[i] == 0) {
            ++ans;
        }
        ++i;
    }
    while (i < n) {
        ll max_cnt = 1;
        map<ll, ll> cnt;
        cnt[0] = 1;
        int j = i + 1;
        while (j < n && a[j] != 0) {
            pre[j] = pre[j - 1] + a[j];
            ++cnt[pre[j]];
            max_cnt = max(max_cnt, cnt[pre[j]]);
            ++j;
        }
        ans += max_cnt;
        i = j;
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
