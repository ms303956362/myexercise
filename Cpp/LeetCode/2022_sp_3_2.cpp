#include "usual.h"

// https://blog.csdn.net/weixin_43983247/article/details/104149084
const int maxn=5e5+5;
struct node
{
    int l,r,sum,lazy;
    node()
    {
        l=r=sum=lazy=0;
    }
} a[maxn];
inline void update(int k)
{
    a[k].sum=a[k*2].sum+a[k*2+1].sum;
}
void build(int k,int l,int r)
{
    a[k].l=l,a[k].r=r;
    a[k].lazy=0;
    if(l==r)
    {
        a[k].sum=0;
        return ;
    }
    int mid=(l+r)/2;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    update(k);
}
void pushdown(int k)
{
    if(a[k].l==a[k].r||!a[k].lazy)
    {
        a[k].lazy=0;
        return ;
    }
    a[k*2].sum=(a[k*2].r-a[k*2].l+1)*a[k].lazy;
    a[k*2+1].sum=(a[k*2+1].r-a[k*2+1].l+1)*a[k].lazy;
    a[k*2].lazy=a[k].lazy;
    a[k*2+1].lazy=a[k].lazy;
    a[k].lazy=0;
}
void changesegment(int k,int l,int r,int x)
{
    if(a[k].l==l&&a[k].r==r)
    {
        a[k].sum=(r-l+1)*x;
        a[k].lazy=x;

        return ;
    }
    pushdown(k);
    int mid=(a[k].l+a[k].r)/2;
    if(r<=mid)
    {
        changesegment(k*2,l,r,x);
    }
    else if(l>mid)
        changesegment(k*2+1,l,r,x);
    else
    {
        changesegment(k*2,l,mid,x);
        changesegment(k*2+1,mid+1,r,x);
    }
    update(k);
}
int query(int k,int l,int r)
{
    if(a[k].lazy)
        pushdown(k);
    if(a[k].l==l&&a[k].r==r)
        return a[k].sum;
    int mid=(a[k].r+a[k].l)/2;
    if(r<=mid)
        return query(k*2,l,r);
    if(l>mid)
        return query(k*2+1,l,r);
    return query(k*2,l,mid)+query(k*2+1,mid+1,r);
}

class Solution {
public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        vector<int> nums;
        function<void(TreeNode *)> dfs = [&](TreeNode *r) {
            if (!r) {
                return;
            }
            dfs(r->left);
            nums.push_back(r->val);
            dfs(r->right);
        };
        dfs(root);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        build(1, 1, n);
        for (const auto& op : ops) {
            int l = lower_bound(nums.begin(), nums.end(), op[1]) - nums.begin() + 1;
            int r = lower_bound(nums.begin(), nums.end(), op[2]) - nums.begin() + 1;
            changesegment(1, l, r, op[0]);
        }
        return query(1, 1, n);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}

