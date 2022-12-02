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

const int mod = 9;

void exgcd(ll a,ll b,ll& d,ll& x,ll& y){
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}

ll inv(ll a, ll p){
    ll d,x,y;
    exgcd(a,p,d,x,y);
    return d == 1 ? (x+p)%p : -1;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int w, m;
    cin >> w >> m;
    vector<int> p(n + 1);
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = (p[i - 1] * 10) % mod;
    }
    int p10 = 1;
    vector<int> pre(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        pre[i] = (pre[i + 1] + p10 * (s[i] - '0')) % mod;
        p10 = (p10 * 10) % mod;
    }
    vector<int> v(n);
    vector<vector<int>> idx(mod);
    for (int i = 0; i <= n - w; ++i) {
        v[i] = ((pre[i] - pre[i + w]) % mod + mod) % mod * inv(p[n - (i + w)], mod) % mod;
        idx[v[i]].push_back(i);
    }
    vector<vector<vector<pair<int, int>>>> ans(mod, vector<vector<pair<int, int>>>(mod));
    for (int vi = 0; vi < mod; ++vi) {
        for (int k = 0; k < mod; ++k) {
            for (int v1 = 0; v1 < mod; ++v1) {
                if (idx[v1].empty()) {
                    continue;
                }
                for (int v2 = 0; v2 < mod; ++v2) {
                    if (idx[v2].empty()) {
                        continue;
                    }
                    if ((v1 * vi + v2) % mod == k) {
                        if (v1 == v2) {
                            if (idx[v1].size() > 1) {
                                ans[vi][k].push_back(make_pair(idx[v1][0], idx[v1][1]));
                            }
                        } else {
                            ans[vi][k].push_back(make_pair(idx[v1][0], idx[v2][0]));
                        }
                    }
                }
            }
            sort(ans[vi][k].begin(), ans[vi][k].end());
        }
    }
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        --l;
        --r;
        int vi = ((pre[l] - pre[r + 1]) + mod) % mod * inv(p[n - (r + 1)], mod) % mod;
        if (ans[vi][k].empty()) {
            cout << -1 << " " << -1 << endl;
        } else {
            cout << ans[vi][k][0].first + 1 << " " << ans[vi][k][0].second + 1 << endl;
        }
        
    }
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
