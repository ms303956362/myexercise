#include "usual.h"

class Solution {
public:
    int findMaxCI(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = 0, cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++cnt;
                ans = max(ans, cnt);
            } else {
                cnt = 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
