#include "usual.h"

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int s1 = 0, s2 = 0;
        vector<int> up1, up2, down1, down2;
        for (const auto& n : nums1) {
            s1 += n;
            up1.push_back(6 - n);
            down1.push_back(n - 1);
        }
        for (const auto& n : nums2) {
            s2 += n;
            up2.push_back(6 - n);
            down2.push_back(n - 1);
        }
        sort(up1.rbegin(), up1.rend());
        sort(up2.rbegin(), up2.rend());
        sort(down1.rbegin(), down1.rend());
        sort(down2.rbegin(), down2.rend());
        int ans = 0, i1 = 0, i2 = 0, s = 0;
        if (s1 < s2) {
            while (s < s2 - s1 && (i1 < n1 || i2 < n2)) {
                if (i2 == n2 || up1[i1] > down2[i2])
                    s += up1[i1++];
                else
                    s += down2[i2++];
                ++ans;
            }
            if (s < s2 - s1)
                return -1;
        } else if (s1 > s2) {
            while (s < s1 - s2 && (i1 < n1 || i2 < n2)) {
                if (i2 == n2 || down1[i1] > up2[i2])
                    s += down1[i1++];
                else
                    s += up2[i2++];
                ++ans;
            }
            if (s < s1 - s2)
                return -1;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1{1,1,1,1,1,1,1}, n2{6};
    cout << Solution().minOperations(n1, n2) << endl;
    return 0;
}
