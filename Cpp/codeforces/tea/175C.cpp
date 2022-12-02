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
ll p[105];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.emplace_back(b, a);
    }
    sort(v.begin(), v.end());
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> p[i];
    }
    p[t] = (ll)1e9 * (ll)1e9;
    int i = 0, j = 0;
    ll f = 1;
    long long ans = 0, sum = 0;
    while (i < n) {
        if (sum + v[i].second < p[j]) {
            ans += v[i].first * v[i].second * f;
            sum += v[i].second;
            ++i;
        } else {
            ans += v[i].first * (p[j] - sum) * f;
            v[i].second -= p[j] - sum;
            sum = p[j];
            ++f;
            ++j;
        }
    }
    cout << ans << endl;
    return 0;
}
