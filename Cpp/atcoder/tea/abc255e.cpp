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
    int n, m;
    cin >> n >> m;
    vector<ll> s(n - 1), a(n), x(m);
    for (int i = 0; i < n - 1; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
    }
    for (int i = n - 2; i >= 0; --i) {
        a[i] = s[i] - a[i + 1];
    }
    unordered_map<ll, ll> cnt;
    for (int i = 0; i < n; ++i) {
        for (const auto& t : x) {
            if (i % 2 == 0) {
                ++cnt[a[i] - t];
            } else {
                ++cnt[t - a[i]];
            }
        }
    }
    ll ans = 0;
    for (const auto& [_, c] : cnt) {
        ans = max(ans, c);
    }
    cout << ans << endl;
    return 0;
}
