#include "usual.h"

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i <= n; ++i) {
            int cnt = 0;
            for (int j = 0; j != n; ++j) {
                if (nums[j] >= i)
                    ++cnt;
            }
            if (cnt == i)
                return i;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
