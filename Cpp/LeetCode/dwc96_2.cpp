#include "usual.h"

using ll = long long;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        // vector<vector<ll>> a1(k), a2(k);
        // for (const auto& num : nums1) {
        //     a1[num % k].push_back(num);
        // }
        // for (const auto& num : nums2) {
        //     a2[num % k].push_back(num);
        // }
        // ll ans = 0, cnt = 0;
        // for (int i = 0; i < k; ++i) {
        //     if (a1[i].size() != a2[i].size()) {
        //         return -1;
        //     }
        //     sort(a1[i].begin(), a1[i].end());
        //     sort(a2[i].begin(), a2[i].end());
        //     int l = a1[i].size();
        //     for (int j = 0; j < l; ++j) {
        //         ans += abs(a1[i][j] - a2[i][j]) / k;
        //         cnt += (a1[i][j] - a2[i][j]) / k;
        //     }
        // }
        // return cnt == 0 ? ans : -1;
        if (k == 0) {
            return nums1 == nums2 ? 0 : -1;
        }
        ll ans = 0, cnt = 0;
        int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            if (abs(nums1[i] - nums2[i]) % k != 0) {
                return -1;
            }
            ans += abs(nums1[i] - nums2[i]) / k;
            cnt += (nums1[i] - nums2[i]) / k;
        }
        return cnt == 0 ? ans : -1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
