#include "usual.h"

typedef long long ll;

const int maxn = 1e5 + 5;
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
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> idx;
        set<int> st(nums.begin(), nums.end());
        int i = 0;
        for (const auto& num : st) {
            idx[num] = i + 1;
            ++i;
        }
        memset(rt, 0, sizeof(struct node) * maxn * 4);
        build(1, 1, n);
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int l = idx.lower_bound(nums[i] - k)->second, r = idx[nums[i]] - 1;
            if (l <= r) {
                int val = fmax(1, l, r) + 1;
                ans = max(ans, val);
                upd(1, r, val);
            } else {
                upd(1, r, 1);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
