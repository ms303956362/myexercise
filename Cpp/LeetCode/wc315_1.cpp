#include "usual.h"

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                for (int j = 0; j < n; ++j) {
                    if (nums[j] == -nums[i]) {
                        ans = max(ans, nums[i]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
