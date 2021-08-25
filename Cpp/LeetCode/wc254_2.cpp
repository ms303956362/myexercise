#include "usual.h"

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int i = 0, j = n - 1;
        for (; i < j; ++i, --j) {
            ans.push_back(nums[j]);
            ans.push_back(nums[i]);
        }
        if (i == j)
            ans.push_back(nums[i]);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
