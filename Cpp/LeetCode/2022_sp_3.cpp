#include "usual.h"

// https://blog.csdn.net/Code92007/article/details/88746032
typedef long long ll;
const int maxn=5e5+10;
ll dat[maxn],cov[maxn];
void pushup(int p)
{
	dat[p]=dat[p<<1]+dat[p<<1|1]; 
} 
void build(int p,int l,int r)
{
	cov[p]=0;
	if(l==r)
	{
		dat[p]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}
void pushdown(int p,int l,int r)
{
	if(cov[p])
	{
		int mid=(l+r)>>1;
		dat[p<<1]=(mid-l+1)*cov[p];
		dat[p<<1|1]=(r-mid)*cov[p];
		cov[p<<1]=cov[p];
		cov[p<<1|1]=cov[p];
		cov[p]=0;
	}
}
void update(int p,int l,int r,int ql,int qr,ll x)//区间赋值 
{
	if(ql<=l&&r<=qr)
	{
		dat[p]=(r-l+1)*x;
		cov[p]=x;
		return;
	}
	pushdown(p,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)update(p<<1,l,mid,ql,qr,x);
	if(qr>=mid+1)update(p<<1|1,mid+1,r,ql,qr,x);
	pushup(p);
}
ll ask(int p,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)return dat[p];
	pushdown(p,l,r);
	ll sum=0;
	int mid=(l+r)>>1;
	if(ql<=mid)sum+=ask(p<<1,l,mid,ql,qr);
	if(qr>=mid+1)sum+=ask(p<<1|1,mid+1,r,ql,qr);
	return sum;
}

class Solution {
public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        memset(dat, 0, maxn * sizeof(ll));
        memset(cov, 0, maxn * sizeof(ll));
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
            update(1, 1, n, l, r, op[0]);
        }
        return ask(1, 1, n, 1, n);
    }
};

class Solution2 {
public:
    int getNumber(vector<int>& nums, vector<vector<int>>& ops) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        build(1, 1, n);
        for (const auto& op : ops) {
            int l = lower_bound(nums.begin(), nums.end(), op[1]) - nums.begin() + 1;
            int r = lower_bound(nums.begin(), nums.end(), op[2]) - nums.begin() + 1;
            update(1, 1, n, l, r, op[0]);
        }
        return ask(1, 1, n, 1, n);
    }
};

class Solution3 {
public:
    int getNumber(vector<int>& nums, vector<vector<int>>& ops) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        function<int(int)> find = [&](int i) {
            return p[i] == i ? i : (p[i] = find(p[i]));
        };
        vector<int> color(n);
        reverse(ops.begin(), ops.end());
        for (const auto& op : ops) {
            int l = lower_bound(nums.begin(), nums.end(), op[1]) - nums.begin();
            int r = lower_bound(nums.begin(), nums.end(), op[2]) - nums.begin();
            for(int j = find(l); j <= r; j = find(j)) {
                color[j] = op[0] + 1;
                p[j] = j + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (color[i] == 2) {
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 3, 4, 5};
    vector<vector<int>> ops{{ 1, 2, 4 }, { 1, 1, 3 }, { 0, 3, 5 }};
    // cout << Solution2().getNumber(nums, ops) << endl;
    cout << Solution3().getNumber(nums, ops) << endl;
    return 0;
}
