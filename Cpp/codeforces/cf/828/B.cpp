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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    ll cnt0 = 0, cnt1 = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] & 1) {
            ++cnt1;
        } else {
            ++cnt0;
        }
        sum += a[i];
    }
    for (int i = 0; i < q; ++i) {
        int t, x;
        cin >> t >> x;
        if (t == 0) {
            sum += cnt0 * x;
            if (x & 1) {
                cnt1 += cnt0;
                cnt0 = 0;
            }
        } else {
            sum += cnt1 * x;
            if (x & 1) {
                cnt0 += cnt1;
                cnt1 = 0;
            }
        }
        cout << sum << endl;
    }
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