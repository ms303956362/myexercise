#include "usual.h"

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        vector<long long> prod1, prod2;
        int n1 = nums1.size(), n2 = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0; i != n1 - 1; ++i) {
            for (int j = i + 1; j != n1; ++j) {
                prod1.push_back((long long)nums1[i] * (long long)nums1[j]);
            }
        }
        for (int i = 0; i != n2 - 1; ++i) {
            for (int j = i + 1; j != n2; ++j) {
                prod2.push_back((long long)nums2[i] * (long long)nums2[j]);
            }
        }
        sort(prod1.begin(), prod1.end());
        sort(prod2.begin(), prod2.end());
        int ans = 0;
        for (int i = 0; i != n1; ++i) {
            auto p1 = lower_bound(prod2.begin(), prod2.end(), (long long)nums1[i] * (long long)nums1[i]);
            auto p2 = upper_bound(prod2.begin(), prod2.end(), (long long)nums1[i] * (long long)nums1[i]);
            ans += p2 - p1;
        }
        for (int i = 0; i != n2; ++i) {
            auto p1 = lower_bound(prod1.begin(), prod1.end(), (long long)nums2[i] * (long long)nums2[i]);
            auto p2 = upper_bound(prod1.begin(), prod1.end(), (long long)nums2[i] * (long long)nums2[i]);
            ans += p2 - p1;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v1{1, 3, 1, 2}, v2{2, 3, 5, 3, 2};
    Solution().numTriplets(v1, v2);
    return 0;
}
