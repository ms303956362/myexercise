#include "usual.h"

using ll = long long;
const int maxn = 1e5 + 5;
const int MAXN = 200010;
const int mod = 1e9 + 7;


ll pow(ll x, ll n, ll mod) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = (ret * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

class DSU {
    int n;
    vector<int> p;  // 祖先
    vector<int> r;  // 树高 
public:
    DSU(int _n) : n(_n), p(_n), r(_n, 0) {
        for (int i = 0; i != n; ++i) {
            p[i] = i;
        }
    }

    int find(int x) {
        if (p[x] == x)
            return x;
        return p[x] = find(p[x]); // x的祖先直接设为根节点，路径压缩
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py)
            return false;
        if (r[px] < r[py])  // 低树的作为高树的子树，高树高度不变
            p[px] = py;
        else {
            p[py] = px;
            if (r[px] == r[py])   // 树高相等，默认px为py祖先，且需px高度加1
                r[px]++;
        }
        return true;
    }
};


class BIT {
    int n;
    vector<int> tree;
public:
    BIT(int _n) : n(_n + 1), tree(_n + 1, 0) {}
    BIT(const vector<int>& a) : n(a.size() + 1), tree(a.size() + 1, 0) {
        for (int i = 1; i < n; ++i) {
            update(i - 1, a[i - 1]);
        }
    }

    inline int lowBit(int i) { return i & (-i); }

    void update(int i, int delta) {
        ++i;
        while (i < n) {
            tree[i] += delta;
            i += lowBit(i);
        }
    }

    int query(int i) {
        ++i;
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= lowBit(i);
        }
        return sum;
    }

};

int prim(vector<vector<pair<int, int>>>& edges) {
    int n = edges.size();
    priority_queue<pair<int, int>> q;
    vector<bool> vst(n, false);
    vst[0] = true;
    for (const auto& e : edges[0]) {
        q.push(e);
    }
    int ans = 0;
    for (int i = 0; i != n - 1; ++i) {
        while (vst[q.top().second])
            q.pop();
        int d = q.top().first, j = q.top().second;
        vst[j] = true;
        ans -= d;
        // cout << "j=" << j << " d=" << -d << " ans=" << ans << endl;
        for (const auto& e : edges[j]) {
            if (!vst[e.second])
                q.push(e);
        }
    }
    return ans;
}



// 离散化
void discrete(const vector<pair<int, int>>& intervals, unordered_map<int, int>& idx) {
    set<int> st;
    for (const auto& [l, r] : intervals) {
        st.insert(l);
        st.insert(r);
    }
    int m = 0;
    unordered_map<int, int> idx;
    for (const auto& x : st) {
        idx[x] = ++m;
    }
}

// 单点更新 + 区间查询
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

// 区间更新 + 区间查询
struct SegTreeNode {
    int l, r;
    ll lazy;
    ll sum;
    ll mx;
    ll mn;
} segTree[MAXN * 4];

void build(int i, int l, int r){
    segTree[i].l = l;
    segTree[i].r = r;
    segTree[i].sum = 0;
    segTree[i].mx = 0;
    segTree[i].mn = 0;
    if(l == r){
        return;
    }
    int mid = (l+r) >> 1;
    build(2*i, l, mid);
    build(2*i + 1, mid+1, r);
    segTree[i].sum = segTree[2*i].sum + segTree[2*i + 1].sum;
    segTree[i].mx = max(segTree[2*i].mx, segTree[2*i + 1].mx);
    segTree[i].mn = min(segTree[2*i].mn, segTree[2*i + 1].mn);
}

void push_up(int i, ll v){
    segTree[i].sum += (segTree[i].r - segTree[i].l + 1) * v;
    segTree[i].mx += v;
    segTree[i].mn += v;
    segTree[i].lazy += v;
}

void push_down(int i){
    if(segTree[i].l == segTree[i].r) return;
    push_up(2*i, segTree[i].lazy);
    push_up(2*i+1, segTree[i].lazy);
    segTree[i].lazy = 0;
}

void add(int i, int l, int r, int v){
    if(segTree[i].l >= l && segTree[i].r <= r){
        push_up(i, v);
        return;
    }
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r) >> 1;
    if(mid >= l){
        add(2*i, l, r, v);
    }
    if(r > mid){
        add(2*i + 1, l, r, v);
    }
    segTree[i].sum = segTree[2*i].sum + segTree[2*i + 1].sum;
    segTree[i].mx = max(segTree[2*i].mx, segTree[2*i + 1].mx);
    segTree[i].mn = min(segTree[2*i].mn, segTree[2*i + 1].mn);
}

ll query_sum(int i, int l, int r){
    if(segTree[i].l == l && segTree[i].r == r){
        return segTree[i].sum;
    }
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r) >> 1;
    if(r <= mid) return query_sum(2*i, l, r);
    else if(l > mid) return query_sum(2*i+1, l, r);
    else{
        return query_sum(2*i, l, mid) + query_sum(2*i+1, mid+1, r);
    }
}

ll query_max(int i, int l, int r){
    if(segTree[i].l == l && segTree[i].r == r){
        return segTree[i].mx;
    }
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r) >> 1;
    if(r <= mid) return query_max(2*i, l, r);
    else if(l > mid) return query_max(2*i+1, l, r);
    else{
        return max(query_max(2*i, l, mid), query_max(2*i+1, mid+1, r));
    }
}

ll query_min(int i, int l, int r){
    if(segTree[i].l == l && segTree[i].r == r){
        return segTree[i].mn;
    }
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r) >> 1;
    if(r <= mid) return query_min(2*i, l, r);
    else if(l > mid) return query_min(2*i+1, l, r);
    else{
        return min(query_min(2*i, l, mid), query_min(2*i+1, mid+1, r));
    }
}

// 组合数
// ll inv[MAXN + 200];
// ll C[MAXN];
void getinv(ll* inv)
{
    inv[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
}

void getfac(ll* C, ll* inv, ll n)
{
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        C[i] = C[i - 1] * (n - i + 1) % mod * inv[i] % mod;
    }

}
