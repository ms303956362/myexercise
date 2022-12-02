// IO
#include <iostream>
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
    ll k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        pre[i] = pre[i + 1] + a[i];
    }
    vector<int> h(m, -1);
    vector<ll> min_h(m, 0x3f3f3f3f3f3f3f3f);
    h[n % m] = n;
    min_h[n % m] = m * pre[n] + k * n;
    ll ans = 0;
    for (int l = n - 1; l >= 0; --l) {
        for (int j = 0; j < m; ++j) {
            if (h[j] == -1) {
                continue;
            }
            int res = ((h[j] - l) % m + m) % m;
            ans = max(ans, m * (pre[l] - pre[h[j]]) - k * (h[j] - l + (res == 0 ? 0 : m - res)));
        }
        if (m * pre[l] + k * l < min_h[l % m]) {
            h[l % m] = l;
            min_h[l % m] = m * pre[l] + k * l;
        }
    }
    cout << ans / m << endl;
    return 0;
}
