#include "usual.h"

class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i % 10 == nums[i])
                return i;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
