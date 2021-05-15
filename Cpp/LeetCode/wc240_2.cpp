#include "usual.h"

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        reverse(nums1.begin(), nums1.end());
        reverse(nums2.begin(), nums2.end());
        int n1 = nums1.size(), n2 = nums2.size();
        int ans = 0;
        for (int i1 = 0; i1 < n1; ++i1) {
            int i = n1 - i1 - 1;
            int j1 = lower_bound(nums2.begin(), nums2.end(), nums1[i1]) - nums2.begin();
            int j = n2 - j1 - 1;
            if (i <= j)
                ans = max(ans, j - i);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
