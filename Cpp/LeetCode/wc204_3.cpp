#include "usual.h"
typedef long long LL;

class Solution {
    int MOD = 1e9 + 7;

public:
    int numOfWays(vector<int>& nums) {
        return helper(nums) - 1;
    }

    int helper(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return 1;
        vector<int> less, more;
        for (int j = 1; j < n; ++j) {
            if (nums[j] < nums[0])
                less.push_back(nums[j]);
            else
                more.push_back(nums[j]);
        }
        int nl = numOfWays(less);
        int nm = numOfWays(more);
        long long C = Lucas(n - 1, nl, MOD);
        return (C % MOD) * (nl % MOD) * (nm % MOD);
    }

    LL fast_power(LL a,LL b,LL p){
        LL ans=1;
        a%=p;
        while(b){
            if(b&1) ans=(ans*a)%p;
            a=(a*a)%p;
            b>>=1;
        }
        return ans;
    }
 
    LL C(LL a,LL b,LL p){
        if(b>a) return 0;
        if(a==b) return 1;
        LL ans1=1,ans2=1;
        for(LL i=1;i<=b;i++){
            ans1=ans1*(a-i+1)%p;
            ans2=ans2*i%p;
        }
        return ans1*fast_power(ans2,p-2,p)%p;
    }
    
    LL Lucas(LL a,LL b,LL p){
        if(b==0) return 1;
        return C(a%p,b%p,p)*Lucas(a/p,b/p,p)%p;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{3,4,5,1,2};
    Solution().numOfWays(nums);
    return 0;
}
