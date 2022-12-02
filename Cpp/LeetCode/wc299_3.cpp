#include "usual.h"

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pre1(n + 1), pre2(n + 1);
        int s1 = 0, s2 = 0;
        for (int i = n - 1; i >= 0; --i) {
            pre1[i] = pre1[i + 1] + nums1[i];
            pre2[i] = pre2[i + 1] + nums2[i];
            s1 += nums1[i];
            s2 += nums2[i];
        }
        int ans = 0, pre1_diff_min = 0, pre2_diff_min = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans = max({ans, 
                s2 + pre1[i] - pre2[i] - pre1_diff_min,
                s1 + pre2[i] - pre1[i] - pre2_diff_min,
            });
            pre1_diff_min = min(pre1_diff_min, pre1[i] - pre2[i]);
            pre2_diff_min = min(pre2_diff_min, pre2[i] - pre1[i]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
