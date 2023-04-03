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
    int n, k;
    cin >> n >> k;
    vector<int> h(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        v.emplace_back(h[i], p[i]);
    }
    sort(v.begin(), v.end());
    multiset<int> st(p.begin(), p.end());
    auto check = [&]() {
        int i = 0, sum = 0;
        while (i < n) {
            sum += k;
            while (i < n && sum >= v[i].first) {
                st.extract(v[i].second);
                ++i;
            }
            k -= *st.begin();
            if (k <= 0) {
                return false;
            }
        }
        return true;
    };
    cout << (check() ? "YES" : "NO") << endl;
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
