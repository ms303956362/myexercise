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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> cnt;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || a[i] == a[i - 1]) {
            ++c;
        } else {
            cnt.push_back(c);
            c = 1;
        }
    }
    cnt.push_back(c);
    int m = cnt.size();
    vector<int> pre(m + 1);
    for (int i = m - 1; i >= 0; --i) {
        pre[i] = pre[i + 1] + cnt[i];
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= m; ++i) {
        int p = 1;
        while (pre[0] - pre[i] > p) {
            p *= 2;
        }
        int c1 = p - (pre[0] - pre[i]), c2 = 0x3f3f3f3f;
        p = 1;
        while (p <= pre[i]) {
            int l = i, h = m, j = i;
            while (l <= h) {
                int k = (l + h) / 2;
                if (pre[k] <= p) {
                    j = k;
                    h = k - 1;
                } else {
                    l = k + 1;
                }
            }
            int q = 1;
            while (q < pre[i] - pre[j]) {
                q *= 2;
            }
            c2 = min(c2, p - pre[j] + q - (pre[i] - pre[j]));
            p *= 2;
        }
        c2 = min(c2, 1 + p - pre[i]);
        ans = min(ans, c1 + c2);
    }
    cout << ans << '\n';
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
