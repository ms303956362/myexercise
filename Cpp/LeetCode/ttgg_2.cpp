#include "usual.h"

// const int maxn = 5e4 + 5;
// // int N, M;
// // int a[maxn], b[maxn];

// // inline int lowbit(const int &x) { return x&-x; }

// // void updata(int x) {
// //     while(x<=N) {
// //         b[x]=a[x];
// //         int lx=lowbit(x);
// //         for(int i=1; i<lx; i<<=1) {
// //             b[x]=max(b[x],b[x-i]);
// //         }
// //         x+=lowbit(x);
// //     }
// // }

// // int query(int x, int y) {
// //     int ans=0;
// //     while(y>=x) {
// //         ans=max(ans,a[y]), --y;
// //         while(y-lowbit(y)>=x) {
// //             ans=max(ans,b[y]);
// //             y-=lowbit(y);
// //         }
// //     }
// //     return ans;
// // }

// struct SegmentTree{
// 	int l,r;
// 	int dat;
// 	#define l(x) tree[x].l
//     #define r(x) tree[x].r
//     #define dat(x) tree[x].dat
// }tree[maxn*4];
// int a[maxn];

// using LL = long long;
// const LL inf = 1e9 + 7;

// void build(int p,int l,int r){
// 	l(p)=l,r(p)=r;
// 	if(l==r){dat(p)=a[l];return;}
// 	int mid=(l+r)/2;
// 	build(p*2,l,mid);
// 	build(p*2+1,mid+1,r);
// 	dat(p)=max(dat(p*2),dat(p*2+1));
// }

// /*void lazy(int p){
// 	if(add(p)){
// 		sum(p*2)+=add(p)*(r(p*2)-l(p*2)+1);
// 		sum(p*2+1)+=add(p)*(r(p*2+1)-l(p*2+1)+1);
// 		add(p*2)+=add(p);
// 		add(p*2+1)+=add(p);
// 		add(p)=0;
// 	}
// }*/

// void change(int p,int x,int z){
// 	if(l(p)==r(p)){
// 		dat(p)=z;return;
// 	}
// 	int mid=(l(p)+r(p))/2;
// 	if(x<=mid) change(p*2,x,z);
//     if(x>mid) change(p*2+1,x,z);
// 	dat(p)=max(dat(p*2),dat(p*2+1));
// }

// LL ask(int p,int l,int r){
// 	if(l<=l(p)&&r>=r(p)) return dat(p);
//     int mid=(l(p)+r(p))/2;
// 	LL ans=-1*inf;
//     if(l<=mid) ans=max(ans,ask(p*2,l,r));
//     if(r>mid) ans=max(ans,ask(p*2+1,l,r));
//     return ans;
// }

// class Solution {
// public:
//     int longestESR(vector<int>& sales) {
//         memset(a, 0, sizeof(a));
//         // memset(b, 0, sizeof(b));
//         int n = sales.size();
//         // N = n;
//         vector<int> v(n), pre(n + 1);
//         for (int i = 0; i < n; ++i) {
//             v[i] = (sales[i] > 8);
//         }
//         for (int i = n - 1; i >= 0; --i) {
//             pre[i] = pre[i + 1] + v[i];
//         }
//         for (int i = 0; i <= n; ++i) {
//             a[2 * pre[i] + i] = i;
//         }
//         // int ans = 0;
//         // updata(2 * pre[n] + n);
//         // for (int i = n - 1; i >= 0; --i) {
//         //     int j = query(0, 2 * pre[i] + i);
//         //     ans = max(ans, j - i);
//         //     updata(2 * pre[i] + i);
//         // }
//         // return ans;
//         unordered_map<int, int> idx;
//         int m = 0;
//         for (int i = 0; i < n; ++i) {
//             if (!idx.count(2 * pre[i] + i)) {
//                 ++m;
//                 idx[2 * pre[i] + i] = m;
//             }
//         }
//         build(1, 1, m);
//         int ans = 0;
//         change(1, idx[2 * pre[n] + n], n);
//         for (int i = n - 1; i >= 0; --i) {
//             int j = ask(1, 1, idx[2 * pre[i] + i]);
//             ans = max(ans, j - i);
//             if (pre[i] != pre[i + 1]) {
//                 change(1, idx[2 * pre[i] + i], i);
//             }
//         }
//         return ans;
//     }
// };

using ll = long long;
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
    int longestESR(vector<int>& sales) {
        int n = sales.size();
        vector<int> v(n), pre(n + 1);
        for (int i = 0; i < n; ++i) {
            v[i] = (sales[i] > 8);
        }
        set<int> st;
        st.insert(2 * pre[n] + n);
        for (int i = n - 1; i >= 0; --i) {
            pre[i] = pre[i + 1] + v[i];
            st.insert(2 * pre[i] + i);
        }
        unordered_map<int, int> idx;
        int m = 0;
        for (const auto& num : st) {
            if (!idx.count(num)) {
                ++m;
                idx[num] = m;
            }
        }
        memset(rt, 0, sizeof(struct node) * maxn * 4);
        build(1, 1, m);
        int ans = 0;
        set<int> ss;
        upd(1, idx[2 * pre[n] + n], n);
        ss.insert(idx[2 * pre[n] + n]);
        for (int i = n - 1; i >= 0; --i) {
            if (idx[2 * pre[i] + i] == 1) {
                continue;
            }
            int j = fmax(1, 1, idx[2 * pre[i] + i] - 1);
            ans = max(ans, j - i);
            if (!ss.count(idx[2 * pre[i] + i])) {
                upd(1, idx[2 * pre[i] + i], i);
                ss.insert(idx[2 * pre[i] + i]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
