#include "usual.h"

class Solution {
    using ll = long long;

public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pre(n + 1), post(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            post[i] = post[i + 1] + nums[i];
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (pre[i] >= post[i]) {
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
