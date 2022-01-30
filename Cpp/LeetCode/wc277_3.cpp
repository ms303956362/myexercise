#include "usual.h"

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if ((i == 0 || nums[i - 1] < nums[i] - 1) && (i == n - 1 || nums[i] + 1 < nums[i + 1])) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
