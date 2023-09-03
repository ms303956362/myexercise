#include "usual.h"

using ll = long long;
const ll maxn = 2 * 1e5 + 5;

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
    int mid = L + R >> 1;
    build(tl(x), L, mid); build(tr(x), mid + 1, R);
    pushup(x);
}

void upd(int x, int pos, ll val) {
    if (rt[x].left == rt[x].right) {
        rt[x].sum = rt[x].mn = rt[x].mx = val;
        return;
    }
    int mid = rt[x].left + rt[x].right >> 1;
    if (pos <= mid)upd(tl(x), pos, val);
    else upd(tr(x), pos, val);
    pushup(x);
}

ll qury(int x, int L, int R) {
    if (L == rt[x].left&&R == rt[x].right) {
        return rt[x].sum;
    }
    int mid = rt[x].left + rt[x].right >> 1;
    if (R <= mid) return qury(tl(x), L, R);
    else if (L > mid) return qury(tr(x), L, R);
    else return qury(tl(x), L, mid) + qury(tr(x), mid + 1, R);
}

ll fmin(int x, int L, int R) {
    if (L == rt[x].left&&R == rt[x].right) {
        return rt[x].mn;
    }
    int mid = rt[x].left + rt[x].right >> 1;
    ll ret = 0x3fffffffffffff;
    if (R <= mid) return min(ret, fmin(tl(x), L, R));
    else if (L > mid) return min(ret, fmin(tr(x), L, R));
    else return min(fmin(tl(x), L, mid), fmin(tr(x), mid + 1, R));
}

ll fmax(int x, int L, int R) {
    if (L == rt[x].left&&R == rt[x].right) {
        return rt[x].mx;
    }
    int mid = rt[x].left + rt[x].right >> 1;
    ll ret = -0x3ffffffffffffff;
    if (R <= mid) return max(ret, fmax(tl(x), L, R));
    else if (L > mid) return max(ret, fmax(tr(x), L, R));
    else return max(fmax(tl(x), L, mid), fmax(tr(x), mid + 1, R));
}

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size(), l = queries.size();
        vector<pair<ll, ll>> pos;
        for (int i = 0; i < n; ++i) {
            pos.emplace_back(nums1[i], nums2[i]);
        }
        sort(pos.begin(), pos.end());
        vector<tuple<ll, ll, int>> q;
        for (int i = 0; i < l; ++i) {
            q.emplace_back(queries[i][0], queries[i][1], i);
        }
        sort(q.begin(), q.end());
        set<ll> st(nums2.begin(), nums2.end());
        map<ll, int> idx;
        int m = 0;
        for (const auto& y : st) {
            idx[y] = ++m;
        }
        build(1, 1, m);
        int i = n - 1, j = l - 1;
        vector<int> ans(l, -1);
        set<int> has;
        unordered_map<int, ll> val;
        while (j >= 0) {
            auto [a, b, k] = q[j];
            while (i >= 0 && pos[i].first >= a) {
                auto [x, y] = pos[i];
                if (x + y > val[y]) {
                    upd(1, idx[y], x + y);
                    val[y] = x + y;
                }
                // cout << idx[y] << endl;
                has.insert(idx[y]);
                --i;
            }
            // cout << i << endl;
            auto ptr = idx.lower_bound(b);
            if (ptr == idx.end()) {
                --j;
                continue;
            }
            int p = ptr->second;
            // cout << p << endl;
            if (has.lower_bound(p) == has.end()) {
                --j;
                continue;
            }
            ans[k] = fmax(1, p, m);
            --j;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
