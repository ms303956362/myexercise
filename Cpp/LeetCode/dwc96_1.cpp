#include "usual.h"

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        for (int i = 0; i < n1; ++i) {
            int j = lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            if (0 <= j && j < n2 && nums2[j] == nums1[i]) {
                return nums1[i];
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
