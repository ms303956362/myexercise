#include "usual.h"

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size(), right_min = nums[n - 1];
        vector<int> rmin(n), lmax(n);
        vector<bool> is2(n, false);
        rmin[n - 1] = INT_MAX;
        for (int i = n - 2; i >= 0; --i) {
            rmin[i] = min(rmin[i + 1], nums[i + 1]);
        }
        lmax[0] = INT_MIN;
        for (int i = 1; i < n; ++i) {
            lmax[i] = max(lmax[i - 1], nums[i - 1]);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (lmax[i] < nums[i] && nums[i] < rmin[i]) {
                is2[i] = true;
                ans += 2;
            }
        }
        for (int i = 1; i < n - 1; ++i)
        {
            if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1] && !is2[i])
            {
                    ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
