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

int check1(vector<int>& vst) {
    int n = vst.size();
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = i + (1 - vst[i]);
        cnt += vst[i];
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] > cnt) {
            ++ans;
        }
    }
    return ans;
}

void solve() {
    int n;
    ll m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.emplace_back(x, -i);
    }
    sort(v.begin(), v.end());
    ll sum = 0;
    vector<int> vst(n, 0);
    for (int i = 0; i < n; ++i) {
        if (sum + v[i].first <= m) {
            sum += v[i].first;
            vst[-v[i].second] = 1;
        } else {
            break;
        }
    }
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = i + (1 - vst[i]);
        cnt += vst[i];
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] > cnt) {
            ++ans;
        }
    }
    vector<ll> pre(n);
    pre[0] = v[0].first;
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] + v[i].first;
    }
    int i = n - 1;
    while (i >= 0 && a[i] > cnt) {
        --i;
    }
    if (i + 1 < n && !vst[i + 1] && m >= v[i + 1].first) {
        ll sum = 0;
        int c = 1;
        for (int j = 0; j < n && sum + v[j].first <= m - v[i + 1].first; ++j) {
            sum += sum + v[j].first;
            ++c;
        }
        if (c >= a[i + 1]) {
            --ans;
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
