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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll l = 1, h = k, turns = 0;
    while (l <= h) {
        ll m = (l + h) / 2, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += min(a[i], m);
        }
        if (sum >= k) {
            h = m - 1;
        } else {
            turns = m;
            l = m + 1;
        }
    }
    ll res = k;
    for (int i = 0; i < n; ++i) {
        res -= min(a[i], turns);
        a[i] -= min(a[i], turns);
    }
    for (int i = 0; i < n && res > 0; ++i) {
        if (a[i] > 0) {
            --a[i];
            --res;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << '\n';
    return 0;
}
