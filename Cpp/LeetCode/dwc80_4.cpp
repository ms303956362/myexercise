#include "usual.h"

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> pre(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            pre[i] = pre[i + 1] + (long long)nums[i];
        }
        long long ans = 0;
        for (long long i = 0; i < n; ++i) {
            long long l = i, h = n;
            while (l <= h) {
                long long m = (l + h) / 2;
                long long sum = pre[i] - pre[m];
                if (sum * (m - i) >= k) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }
            ans += h - i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{2, 1, 4, 3, 5};
    int k = 10;
    Solution().countSubarrays(v, k);
    return 0;
}
