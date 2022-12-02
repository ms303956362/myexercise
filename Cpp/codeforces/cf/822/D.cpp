// IO
#include <iostream>
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

bool check(vector<ll>& a, int n, int k) {
    queue<pair<ll, ll>> q;
    ll sum = 0, min_sum = 0;
    for (ll i = k; i > 0; --i) {
        sum += a[i];
        min_sum = min(min_sum, sum);
        if (sum > 0) {
            q.emplace(sum, min_sum);
            sum = 0;
            min_sum = 0;
        }
    }
    ll curr = 0;
    for (ll i = k + 1; i <= n; ++i) {
        while (!q.empty() && curr + q.front().second >= 0) {
            curr += q.front().first;
            q.pop();
        }
        curr += a[i];
        if (curr < 0) {
            return false;
        }
    }
    return true;
}

bool solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 2);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (check(a, n, k)) {
        return true;
    }
    reverse(a.begin(), a.end());
    k = n + 1 - k;
    return check(a, n, k);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        if (solve()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
