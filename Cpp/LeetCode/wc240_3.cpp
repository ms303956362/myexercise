#include "usual.h"

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size(), MOD = 1e9 + 7;
        vector<int> r(n), s;
        vector<long long> p(n + 1);
        for (int i = 0; i < n; ++i)
            p[i + 1] = p[i] + nums[i];
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.back()] > nums[i]) {
                r[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }
        while (!s.empty()) {
            r[s.back()] = n;
            s.pop_back();
        }
        long long ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.back()] > nums[i]) {
                ans = max(ans, (long long)nums[s.back()] * (p[r[s.back()]] - p[i + 1]));
                s.pop_back();
            }
            s.push_back(i);
        }
        while (!s.empty()) {
            ans = max(ans, (long long)nums[s.back()] * (p[r[s.back()]] - p[0]));
            s.pop_back();
        }
        return ans % MOD;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{2,3,3,1,2};
    Solution().maxSumMinProduct(a);
    return 0;
}
