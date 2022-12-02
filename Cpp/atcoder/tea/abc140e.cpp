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
    int n;
    cin >> n;
    list<pair<int, int>> l;
    vector<list<pair<int, int>>::iterator> p(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        l.emplace_back(x, i);
        p[x] = prev(l.end());
    }
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        auto ptr = p[i];
        ll l1 = -1, l2 = -1, r1 = n, r2 = n;
        if (ptr != l.begin()) {
            auto q = prev(ptr);
            l1 = q->second;
            if (q != l.begin()) {
                l2 = prev(q)->second;
            }
        }
        if (next(ptr) != l.end()) {
            auto q = next(ptr);
            r1 = q->second;
            if (next(q) != l.end()) {
                r2 = next(q)->second;
            }
        }
        ans += ((l1 - l2) * (r1 - ptr->second) + (r2 - r1) * (ptr->second - l1)) * ptr->first;
        l.erase(ptr);
    }
    cout << ans << endl;
    // vector<ll> r1(n, n), r2(n, n), l1(n, -1), l2(n, -1);
    // stack<int> s;
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    // for (int i = 0; i < n; ++i) {
    //     while (!q.empty() && q.top().first < a[i]) {
    //         r2[q.top().second] = i;
    //         q.pop();
    //     }
    //     while (!s.empty() && a[s.top()] < a[i]) {
    //         r1[s.top()] = i;
    //         q.emplace(a[s.top()], s.top());
    //         s.pop();
    //     }
    //     s.push(i);
    // }
    // while (!s.empty()) {
    //     s.pop();
    // }
    // while (!q.empty()) {
    //     q.pop();
    // }
    // for (int i = n - 1; i >= 0; --i) {
    //     while (!q.empty() && q.top().first < a[i]) {
    //         l2[q.top().second] = i;
    //         q.pop();
    //     }
    //     while (!s.empty() && a[s.top()] < a[i]) {
    //         l1[s.top()] = i;
    //         q.emplace(a[s.top()], s.top());
    //         s.pop();
    //     }
    //     s.push(i);
    // }
    // ll ans = 0;
    // for (int i = 0; i < n; ++i) {
    //     ans += ((l1[i] - l2[i]) * (r1[i] - i) + (r2[i] - r1[i]) * (i - l1[i])) * a[i];
    // }
    // cout << ans << endl;
    return 0;
}
