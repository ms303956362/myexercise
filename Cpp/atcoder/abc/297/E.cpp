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
    sort(a.begin(), a.end());
    set<ll> vst;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 0; i < n; ++i) {
        if (!vst.count(a[i])) {
            q.push(a[i]);
            vst.insert(a[i]);
        }
    }
    ll ans = 0;
    while (k--) {
        auto u = q.top();
        q.pop();
        ans = u;
        for (int i = 0; i < n; ++i) {
            if (!vst.count(u + a[i])) {
                vst.insert(u + a[i]);
                q.push(u + a[i]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
