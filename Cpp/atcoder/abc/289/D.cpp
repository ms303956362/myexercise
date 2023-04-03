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
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    set<int> traps(b.begin(), b.end());
    int x;
    cin >> x;
    vector<bool> dp(x + 1);
    dp[0] = true;
    for (int i = 1; i <= x; ++i) {
        if (traps.count(i)) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (i >= a[j]) {
                dp[i] = (dp[i] || dp[i - a[j]]);
            }
        }
    }
    cout << (dp[x] ? "Yes" : "No") << '\n';
    return 0;
}
