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
    int res = n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
        int cnt = 0;
        while (x % 2 == 0) {
            ++cnt;
            x /= 2;
        }
        res -= cnt;
    }
    if (res <= 0) {
        cout << 0 << endl;
        return;
    }
    priority_queue<int> q;
    for (int i = 2; i <= n; i += 2) {
        int cnt = 0, x = i;
        while (x % 2 == 0) {
            ++cnt;
            x /= 2;
        }
        q.emplace(cnt);
    }
    int ans = 0;
    while (res > 0 && !q.empty()) {
        res -= q.top();
        q.pop();
        ++ans;
    }
    cout << (res > 0 ? -1 : ans) << endl;
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
