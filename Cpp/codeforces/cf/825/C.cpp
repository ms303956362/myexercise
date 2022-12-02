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

// const int maxn = 4e5 + 1000;
// struct node {
//     int left, right;
//     int  mx, mn;
//     ll sum;
// }rt[maxn * 4];

// int tl(int x) { return x * 2; }
// int tr(int x) { return x * 2 + 1; }

// void pushup(int x) {
//     rt[x].sum = rt[tl(x)].sum + rt[tr(x)].sum;
//     rt[x].mx = max(rt[tl(x)].mx, rt[tr(x)].mx);
//     rt[x].mn = min(rt[tl(x)].mn, rt[tr(x)].mn);
// }

// void build(int x,int L,int R) {
//     rt[x].left = L; rt[x].right = R;
//     if (L == R) {
//         rt[x].sum = rt[x].mn = rt[x].mx = maxn;
//         return;
//     }
//     int mid = L + R >> 1;
//     build(tl(x), L, mid); build(tr(x), mid + 1, R);
//     pushup(x);
// }

// void upd(int x, int pos, ll val) {
//     if (rt[x].left == rt[x].right) {
//         rt[x].sum = rt[x].mn = rt[x].mx = val;
//         return;
//     }
//     int mid = rt[x].left + rt[x].right >> 1;
//     if (pos <= mid)upd(tl(x), pos, val);
//     else upd(tr(x), pos, val);
//     pushup(x);
// }

// ll qury(int x, int L, int R) {
//     if (L == rt[x].left&&R == rt[x].right) {
//         return rt[x].sum;
//     }
//     int mid = rt[x].left + rt[x].right >> 1;
//     if (R <= mid) return qury(tl(x), L, R);
//     else if (L > mid) return qury(tr(x), L, R);
//     else return qury(tl(x), L, mid) + qury(tr(x), mid + 1, R);
// }

// ll fmin(int x, int L, int R) {
//     if (L == rt[x].left&&R == rt[x].right) {
//         return rt[x].mn;
//     }
//     int mid = rt[x].left + rt[x].right >> 1;
//     ll ret = 0x3fffffffffffff;
//     if (R <= mid) return min(ret, fmin(tl(x), L, R));
//     else if (L > mid) return min(ret, fmin(tr(x), L, R));
//     else return min(fmin(tl(x), L, mid), fmin(tr(x), mid + 1, R));
// }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // build(1, 1, maxn);
    // int offset = 2e5 + 100;
    // ll ans = 0;
    // upd(1, n + offset, n);
    // for (int i = n - 1; i >= 0; --i) {
    //     int j = fmin(1, i + offset, maxn);
    //     ll l = j - i;
    //     ans += l;
    //     upd(1, i - a[i] + offset, i);
    // }
    // cout << ans << endl;
    vector<ll> dp(n);
    ll ans = 1;
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i] = min(dp[i - 1] + 1, (ll)a[i]);
        ans += dp[i];
    }
    cout << ans << endl;
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
