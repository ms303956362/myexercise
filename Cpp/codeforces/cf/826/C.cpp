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
    int sum = 0, ans = n;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        int max_len = i + 1, j = i + 1, k = i + 1, curr = 0;
        bool ok = true;
        while (j < n) {
            while (j < n && curr < sum) {
                curr += a[j];
                ++j;
            }
            if (curr != sum) {
                ok = false;
                break;
            }
            max_len = max(max_len , j - k);
            k = j;
            curr = 0;
        }
        if (ok) {
            ans = min(ans, max_len);
        }
    }
    cout << ans << endl;
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
