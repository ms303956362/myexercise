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

class BIT {
    ll n;
    vector<ll> tree;
public:
    BIT(ll _n) : n(_n + 1), tree(_n + 1, 0) {}
    BIT(const vector<ll>& a) : n(a.size() + 1), tree(a.size() + 1, 0) {
        for (ll i = 1; i < n; ++i) {
            update(i - 1, a[i - 1]);
        }
    }

    inline ll lowBit(ll i) { return i & (-i); }

    void update(ll i, ll delta) {
        ++i;
        while (i < n) {
            tree[i] += delta;
            i += lowBit(i);
        }
    }

    ll query(ll i) {
        ++i;
        ll sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= lowBit(i);
        }
        return sum;
    }

};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n), b(m);
    vector<tuple<int, int, int>> qs;
    set<int> sa, sb;
    sa.insert(0);
    sb.insert(0);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        --x;
        qs.emplace_back(t, x, y);
        if (t == 1) {
            sa.insert(y);
        } else if (t == 2) {
            sb.insert(y);
        }
    }
    unordered_map<int, int> idxa, idxb;
    int la = 0, lb = 0;
    for (const auto& num : sa) {
        idxa[num] = la++;
    }
    for (const auto& num : sb) {
        idxb[num] = lb++;
    }
    multiset<ll> ma, mb;
    for (int i = 0; i < n; ++i) {
        ma.insert(0);
    }
    for (int i = 0; i < m; ++i) {
        mb.insert(0);
    }
    BIT cnta(la), suma(la), cntb(lb), sumb(lb);
    cnta.update(idxa[0], n);
    cntb.update(idxb[0], m);
    ll ans = 0;
    for (const auto& [t, x, y] : qs) {
        if (t == 1) {
            ll a_old = a[x], a_new = y;
            ll j = 0, k = 0;
            auto p = mb.upper_bound(a_old), q = mb.upper_bound(a_new);
            if (p != mb.begin()) {
                j = cntb.query(idxb[*prev(p)]);
            }
            if (q != mb.begin()) {
                k = cntb.query(idxb[*prev(q)]);
            }
            ll old_sum = j* a_old + sumb.query(lb) - sumb.query(idxb[b[j]]), new_sum = k * a_new + sumb.query(lb) - sumb.query(idxb[b[k]]);
            ans += new_sum - old_sum;
            a[x] = a_new;
            ma.erase(ma.lower_bound(a_old));
            ma.insert(a_new);
            cnta.update(idxa[a_new], 1);
            cnta.update(idxa[a_old], -1);
            suma.update(idxa[a_new], a_new);
            suma.update(idxa[a_old], -a_old);
        } else {
            ll b_old = b[x], b_new = y;
            ll j = 0, k = 0;
            auto p = ma.upper_bound(b_old), q = ma.upper_bound(b_new);
            if (p != ma.begin()) {
                j = cnta.query(idxa[*prev(p)]);
            }
            if (q != ma.begin()) {
                k = cnta.query(idxa[*prev(q)]);
            }
            ll old_sum = j * b_old + suma.query(la) - suma.query(idxa[a[j]]), new_sum = k * b_new + suma.query(la) - suma.query(idxa[a[k]]);
            ans += new_sum - old_sum;
            b[x] = b_new;
            mb.erase(mb.lower_bound(b_old));
            mb.insert(b_new);
            cntb.update(idxb[b_new], 1);
            cntb.update(idxb[b_old], -1);
            sumb.update(idxb[b_new], b_new);
            sumb.update(idxb[b_old], -b_old);
        }
        cout << ans << endl;
    }
    return 0;
}
