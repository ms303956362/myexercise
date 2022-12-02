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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b0, b1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            if (a[i] == 0) {
                b0.push_back(x);
            } else {
                b1.push_back(x);
            }
        }
        ll cnt0 = b0.size(), cnt1 = b1.size();
        sort(b0.begin(), b0.end());
        sort(b1.begin(), b1.end());
        if (cnt0 == cnt1) {
            ll sum = 0, min_num = 1e9 + 7;
            for (auto b : b0) {
                sum += b;
                min_num = min(min_num, b);
            }
            for (auto b : b1) {
                sum += b;
                min_num = min(min_num, b);
            }
            cout << 2 * sum - min_num << endl;
        } else if (cnt0 < cnt1) {
            ll ans = b1[0];
            for (const auto& b : b0) {
                ans += 2 * b;
            }
            for (int i = cnt1 - 1; i >= cnt1 - cnt0; --i) {
                ans += 2 * b1[i];
            }
            for (int i = cnt1 - cnt0 - 1; i > 0; --i) {
                ans += b1[i];
            }
            cout << ans << endl;
        } else {
            ll ans = b0[0];
            for (const auto& b : b1) {
                ans += 2 * b;
            }
            for (int i = cnt0 - 1; i >= cnt0 - cnt1; --i) {
                ans += 2 * b0[i];
            }
            for (int i = cnt0 - cnt1 - 1; i > 0; --i) {
                ans += b0[i];
            }
            cout << ans << endl;
        }
    }
    return 0;
}
