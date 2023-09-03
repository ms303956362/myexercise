#include "usual.h"

class Solution {
public:
    long long minCost(vector<int>& nums1, int x1) {
        vector<long long> nums(nums1.begin(), nums1.end());
        long long x = x1, n = nums.size();
        vector<vector<long long>> min_cost(n, vector<long long>(n));
        for (int i = 0; i < n; ++i) {
            min_cost[i][0] = nums[i];
            int k = (i + 1) % n;
            for (int j = 1; j < n; ++j) {
                min_cost[i][j] = min(min_cost[i][j - 1], nums[k]);
                k = (k + 1) % n;
            }
        }
        long long ans = 0x3f3f3f3f3f3f3f3f;
        for (long long k = 0; k < n; ++k) {
            long long cost = k * x;
            for (int i = 0; i < n; ++i) {
                cost += min_cost[i][k];
            }
            ans = min(ans, cost);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
