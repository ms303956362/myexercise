#include "usual.h"

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        int sum = 0, i = 0;
        for (i = 0; i < n && i < 2 * k + 1; ++i) {
            sum += nums[i];
        }
        if (i < n) {
            ans[k] = sum / (2 * k + 1);
        }
        for (int i = 1, j = 2 * k + 1; j < n; ++i, ++j) {
            sum = sum - nums[i - 1] + nums[j];
            ans[(i + j) / 2] = sum / (2 * k + 1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
