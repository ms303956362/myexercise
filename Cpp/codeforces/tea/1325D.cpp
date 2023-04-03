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
    ll u, v;
    cin >> u >> v;
    if (u > v || (u - v) % 2) {
        cout << -1 << '\n';
        return;
    }
    vector<ll> ans;
    if (u != 0) {
        ans.push_back(u);
    }
    ll diff = v - u;
    ll mask = 2;
    for (int i = 0; i < 60; ++i) {
        if (diff & mask) {
            ll k = mask / 2;
            int cnt = 0, l = ans.size();
            for (int j = 0; j < l && cnt < 2; ++j) {
                if ((k & ans[j]) == 0) {
                    ans[j] |= k;
                    ++cnt;
                }
            }
            if (cnt < 2) {
                for (int j = 0; j < 2 - cnt; ++j) {
                    ans.push_back(k);
                }
            }
        }
        mask <<= 1;
    }
    cout << ans.size() << '\n';
    for (const auto& num : ans) {
        cout << num << ' ';
    }
    cout << '\n';
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
