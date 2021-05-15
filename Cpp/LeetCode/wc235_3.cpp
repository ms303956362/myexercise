#include "usual.h"

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums2, vector<int>& nums1) {
        int n = nums1.size();
        vector<pair<int, int>> nums2_p;
        for (int i = 0; i != n; ++i) {
            nums2_p.push_back({nums2[i], i});
        }
        sort(nums2_p.begin(), nums2_p.end());
        vector<int> nums3, idx;
        for (const auto&[num, i] : nums2_p) {
            nums3.push_back(num);
            idx.push_back(i);
        }
        int ans = 0, MOD = 1e9 + 7, max_drop = 0;
        for (int i = 0; i != n; ++i) {
            ans = (ans + abs(nums1[i] - nums2[i])) % MOD;
            int j = lower_bound(nums3.begin(), nums3.end(), nums1[i]) - nums3.begin();
            if (j < n) {
                max_drop = max(max_drop, nums3[j] - nums1[i] + abs(nums2[idx[j]] - nums1[i]));
            }
            if (j > 0) {
                --j;
                max_drop = max(max_drop, nums1[i] - nums3[j] + abs(nums2[idx[j]] - nums1[i]));
            }
        }
        return ans - max_drop;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v1{1, 7, 5}, v2{2, 3, 5};
    Solution().minAbsoluteSumDiff(v1, v2);
    return 0;
}
