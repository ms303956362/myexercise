#include "usual.h"

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 0, r = INT_MAX;
        for (const auto& x : nums)
            r = min(r, x);
        int m = r, op = 0;
        int ans = 0;
        while (l <= r) {
            m = (l + r) >> 1;
            op = 0;
            for (const auto& x : nums)
                op += (x - 1) / m;
            if (op <= maxOperations)
                l = m + 1;
            else
                r = m - 1;
        }
        return m;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
