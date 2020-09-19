#include "usual.h"

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size(), m = requests.size();
        vector<long long> cnt(n, 0);
        vector<int> s, e;
        long long MOD = 1e9 + 7;
        for (auto& r : requests) {
            s.push_back(r[0]);
            e.push_back(r[1]);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        for (int i = 0; i != n; ++i) {
            int n1 = upper_bound(s.begin(), s.end(), i) - s.begin(), n2 = m - n1;
            int n3 = lower_bound(e.begin(), e.end(), i) - e.begin(), n4 = m - n3;
            cnt[i] = n1 + n4 - n2 - n3;
        }
        sort(cnt.begin(), cnt.end());
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i != n; ++i) {
            ans = (ans + (cnt[i] * nums[i]) % MOD) % MOD;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 3, 4, 5};
    vector<vector<int>> requests{{ 1, 3 }, { 0, 1 }};
    Solution().maxSumRangeQuery(nums, requests);
    return 0;
}
