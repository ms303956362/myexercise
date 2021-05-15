#include "usual.h"

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        for (int i = start, j = start; i < n || j >= 0; ++i, --j) {
            if (j >= 0 && nums[j] == target)
                return start - j;
            if (i < n && nums[i] == target)
                return i - start;
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
