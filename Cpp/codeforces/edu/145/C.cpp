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
    vector<int> ans(n, -999);
    int p = 0;
    while (p * (p + 1) / 2 <= k) {
        ++p;
    }
    --p;
    if (p > 0) {
        for (int i = 0; i < p; ++i) {
            ans[i] = p - i + 1;
        }
        k -= p * (p + 1) / 2;
        int s = 0;
        for (int i = p - 1; i >= k; --i) {
            s += ans[i];
        }
        if (p < n) {
            ans[p] = -s - 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
