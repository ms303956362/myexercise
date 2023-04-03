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
const int maxn = 2e5 + 5;

struct node {
    int left, right;
    int  mx, mn;
    ll sum;
}rt[maxn * 4];

int tl(int x) { return x * 2; }
int tr(int x) { return x * 2 + 1; }

void pushup(int x) {
    rt[x].sum = rt[tl(x)].sum + rt[tr(x)].sum;
    rt[x].mx = max(rt[tl(x)].mx, rt[tr(x)].mx);
    rt[x].mn = min(rt[tl(x)].mn, rt[tr(x)].mn);
}

void build(int x,int L,int R) {
    rt[x].left = L; rt[x].right = R;
    if (L == R) {
        rt[x].sum = rt[x].mn = rt[x].mx = 0;
        return;
    }
    int mid = (L + R) >> 1;
    build(tl(x), L, mid); build(tr(x), mid + 1, R);
    pushup(x);
}

void upd(int x, int pos, ll val) {
    if (rt[x].left == rt[x].right) {
        rt[x].sum = rt[x].mn = rt[x].mx = val;
        return;
    }
    int mid = (rt[x].left + rt[x].right) >> 1;
    if (pos <= mid)upd(tl(x), pos, val);
    else upd(tr(x), pos, val);
    pushup(x);
}

ll qury(int x, int L, int R) {
    if (L == rt[x].left&&R == rt[x].right) {
        return rt[x].sum;
    }
    int mid = (rt[x].left + rt[x].right) >> 1;
    if (R <= mid) return qury(tl(x), L, R);
    else if (L > mid) return qury(tr(x), L, R);
    else return qury(tl(x), L, mid) + qury(tr(x), mid + 1, R);
}

ll fmin(int x, int L, int R) {
    if (L == rt[x].left&&R == rt[x].right) {
        return rt[x].mn;
    }
    int mid = (rt[x].left + rt[x].right) >> 1;
    ll ret = 0x3fffffffffffff;
    if (R <= mid) return min(ret, fmin(tl(x), L, R));
    else if (L > mid) return min(ret, fmin(tr(x), L, R));
    else return min(fmin(tl(x), L, mid), fmin(tr(x), mid + 1, R));
}

ll fmax(int x, int L, int R) {
    if (L == rt[x].left&&R == rt[x].right) {
        return rt[x].mx;
    }
    int mid = (rt[x].left + rt[x].right) >> 1;
    ll ret = -0x3ffffffffffffff;
    if (R <= mid) return max(ret, fmax(tl(x), L, R));
    else if (L > mid) return max(ret, fmax(tr(x), L, R));
    else return max(fmax(tl(x), L, mid), fmax(tr(x), mid + 1, R));
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> pre1(n + 1), pre2(n + 1);
    for (int i = 0; i < n; ++i) {
        pre1[i + 1] = pre1[i] + a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        pre2[i] = pre2[i + 1] + a[i];
    }
    vector<int> l(n, -1), r(n, n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            l[i] = st.top();
        }
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            r[i] = st.top();
        }
        st.push(i);
    }
    build(1, 1, n + 1);
    for (int i = 0; i <= n; ++i) {
        upd(1, i + 1, pre2[i]);
    }
    for (int i = 0; i < n; ++i) {
        ll pre = fmin(1, i + 2, r[i] + 1);
        if (pre < pre2[i] - a[i]) {
            cout << "No" << '\n';
            return;
        }
        pre = fmax(1, l[i] + 2, i + 1);
        if (pre2[i + 1] < pre - a[i]) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
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