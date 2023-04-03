#include "usual.h"

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int ls = 0, rs = 0;
            for (int j = 0; j < i; ++j) {
                ls += nums[j];
            }
            for (int j = n - 1; j > i; --j) {
                rs += nums[j];
            }
            ans.push_back(abs(ls - rs));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
