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
    priority_queue<ll, vector<ll>, greater<ll>> q;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        q.push(x);
        sum += x;
    }
    for (int i = 0; i < m; ++i) {
        ll x;
        cin >> x;
        sum -= q.top();
        q.pop();
        sum += x;
        q.push(x);
    }
    cout << sum << endl;
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
