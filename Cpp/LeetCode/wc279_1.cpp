#include "usual.h"

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> v1, v2;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 1) {
                v1.push_back(nums[i]);
            } else {
                v2.push_back(nums[i]);
            }
        }
        sort(v1.rbegin(), v1.rend());
        sort(v2.begin(), v2.end());
        vector<int> ans(n);
        int j = 0, k = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                ans[i] = v2[k];
                ++k;
            } else {
                ans[i] = v1[j];
                ++j;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
