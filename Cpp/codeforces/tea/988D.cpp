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
    set<ll> st;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        st.insert(x);
    }
    int ans = 1;
    vector<int> v(3);
    v[0] = *st.begin();
    for (const auto& x : st) {
        ll pd = 1;
        while (pd <= 0x3f3f3f3f3f) {
            bool ok1 = st.count(x + pd), ok2 = st.count(x - pd);
            if (ok1 + ok2 + 1 > ans) {
                v[0] = x;
                ans = ok1 + ok2 + 1;
                if (ok1) {
                    v[1] = x + pd;
                }
                if (ok2) {
                    v[2] = x - pd;
                }
            }
            pd *= 2;
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < ans; ++i) {
        cout << v[i] << ' ';
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
