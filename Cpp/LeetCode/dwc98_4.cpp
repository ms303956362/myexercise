#include "usual.h"

#define lson rt<<1,L,mid
#define rson rt<<1|1,mid+1,R

const long long maxn=100005;
long long n;

struct Node{
    long long num0,num1;  //统计该区间0和1的个数
    bool flag;
}tree[maxn<<2];

void pushUp(long long rt){
    tree[rt].num0=tree[rt<<1].num0+tree[rt<<1|1].num0;
    tree[rt].num1=tree[rt<<1].num1+tree[rt<<1|1].num1;
}
void build(long long rt,long long L,long long R){
    tree[rt].num0=R-L+1;
    tree[rt].num1=0;
    tree[rt].flag=false;
    if(L==R)
        return;
    long long mid=(L+R)>>1;
    build(lson);
    build(rson);
    pushUp(rt);
}

void pushDown(Node &rt,Node &ls,Node &rs){
    if(rt.flag){
        ls.flag=!ls.flag;  //一开始将ls和rs的flag直接设为true了，导致WA。。。
        rs.flag=!rs.flag;
        swap(ls.num0,ls.num1);
        swap(rs.num0,rs.num1);
        rt.flag=false;
    }
}
void update(long long rt,long long L,long long R,long long l,long long r){
    if(l<=L&&R<=r){
        tree[rt].flag=!tree[rt].flag;
        swap(tree[rt].num0,tree[rt].num1);
        return;
    }
    pushDown(tree[rt],tree[rt<<1],tree[rt<<1|1]);
    long long mid=(R+L)>>1;
    if(l<=mid)
        update(lson,l,r);
    if(r>mid)
        update(rson,l,r);
    pushUp(rt);
}

long long query(long long rt,long long L,long long R,long long l,long long r){
    if(l<=L&&R<=r){
        return tree[rt].num1;
    }
    pushDown(tree[rt],tree[rt<<1],tree[rt<<1|1]);
    long long mid=(L+R)>>1;
    long long ret=0;
    if(l<=mid)
        ret+=query(lson,l,r);
    if(r>mid)
        ret+=query(rson,l,r);
    return ret;
}

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        n = nums1.size();
        memset(tree, 0, sizeof(Node)*(maxn<<2));
        build(1,1,n);
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (nums1[i] == 1) {
                update(1, 1, n, i + 1, i + 1);
            }
            sum += nums2[i];
        }
        vector<long long> ans;
        for (const auto& q : queries) {
            if (q[0] == 1) {
                update(1, 1, n, q[1] + 1, q[2] + 1);
            } else if (q[0] == 2) {
                sum += q[1] * query(1, 1, n, 1, n);
            } else {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
