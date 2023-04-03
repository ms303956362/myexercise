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
    ll x;
    cin >> n >> x;
    vector<ll> d(2 * n);
    ll total = 0, totald = 0;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        totald += d[i];
        total += (1 + d[i]) * d[i] / 2;
    }
    ll base = 0;
    if (x > 2 * totald) {
        base = (x / (2 * totald)) * (2 * total);
        x %= 2 * totald;
    }
    for (int i = n; i < 2 * n; ++i) {
        d[i] = d[i - n];
    }
    vector<ll> pre(2 * n + 1), pred(2 * n + 1);
    for (int i = 0; i < 2 * n; ++i) {
        pred[i + 1] = pred[i] + d[i];
        pre[i + 1] = pre[i] + (1 + d[i]) * d[i] / 2;
    }
    int i = 1, j = 0;
    ll extra = 0;
    while (i <= 2 * n) {
        while (j < i && pred[i] - pred[j] > x) {
            ++j;
        }
        if (j > 0) {
            ll y = x - (pred[i] - pred[j]);
            extra = max(extra, pre[i] - pre[j] + (d[j - 1] - y + 1 + d[j - 1]) * y / 2);
        }
        ++i;
    }
    cout << base + extra << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
