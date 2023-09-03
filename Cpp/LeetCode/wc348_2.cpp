#include "usual.h"

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size(), idx1 = 0, idxn = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                idx1 = i;
            } else if (nums[i] == n) {
                idxn = i;
            }
        }
        if (idx1 < idxn) {
            return idx1 + n - 1 - idxn;
        }
        return idx1 + n - 1 - idxn - 1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
