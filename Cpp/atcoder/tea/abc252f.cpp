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
    ll n, l;
    cin >> n >> l;
    ll sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        sum += x;
        q.push(x);
    }
    if (sum < l) {
        q.push(l - sum);
    }
    ll ans = 0;
    while (q.size() > 1) {
        ll x = q.top();
        q.pop();
        ll y = q.top();
        q.pop();
        ans += x + y;
        q.push(x + y);
    }
    cout << ans << endl;
    return 0;
}
