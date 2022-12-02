#include "usual.h"

using ll = long long;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int, int>> pr;
        for (int i = 0; i < n; ++i) {
            pr.emplace_back(nums[i], cost[i]);
        }
        sort(pr.begin(), pr.end());
        vector<ll> a(n), c(n), pre(n + 1);
        ll curr = 0;
        for (int i = n - 1; i >= 0; --i) {
            a[i] = pr[i].first;
            c[i] = pr[i].second;
            pre[i] = pre[i + 1] + c[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            curr += c[i] * (a[i] - a[0]);
        }
        ll ans = curr;
        for (int i = 1; i < n; ++i) {
            ll d = a[i] - a[i - 1];
            curr += i * d * (pre[0] - pre[i]) - (n - i) * d * pre[i];
            ans = min(ans, curr);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
