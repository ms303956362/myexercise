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
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + 1), cap(m);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    for (int i = 0; i < m; ++i) {
        cin >> cap[i];
    }
    sort(cap.rbegin(), cap.rend());
    priority_queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] > 0) {
            q.push(cnt[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < m && !q.empty(); ++i) {
        int x = q.top();
        q.pop();
        if (cap[i] >= x) {
            ans += x;
        } else {
            ans += cap[i];
            q.push(x - cap[i]);
        }
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
