#include "usual.h"

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int psum = 0, nsum = 0;
        int n = nums.size();
        int max_psum = 0, max_nsum = 0;
        for (int i = 0; i != n; ++i) {
            psum += nums[i];
            if (psum < 0)
                psum = 0;
            max_psum = max(max_psum, psum);
            nsum += nums[i];
            if (nsum > 0)
                nsum = 0;
            max_nsum = min(max_nsum, nsum);
        }
        return max(max_psum, -max_nsum);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
