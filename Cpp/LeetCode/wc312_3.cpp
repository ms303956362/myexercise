#include "usual.h"

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        vector<int> left(n, n), right(n, -1);
        while (i < n) {
            int j = i + 1;
            left[i] = i;
            while (j < n && nums[j] <= nums[j - 1]) {
                left[j] = i;
                ++j;
            }
            i = j;
        }
        i = n - 1;
        while (i >= 0) {
            int j = i - 1;
            right[i] = i;
            while (j >= 0 && nums[j] <= nums[j + 1]) {
                right[j] = i;
                --j;
            }
            i = j;
        }
        vector<int> ans;
        for (int i = k; i < n - k; ++i) {
            if (left[i - 1] <= i - 1 - k && right[i + 1] >= i + 1 + k) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
