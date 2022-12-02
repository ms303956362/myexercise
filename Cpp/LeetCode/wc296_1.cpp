#include "usual.h"

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        while (n > 1) {
            vector<int> tmp;
            for (int i = 0; i < n / 2; ++i) {
                if (i % 2 == 0) {
                    tmp.push_back(min(nums[2 * i], nums[2 * i + 1]));
                } else {
                    tmp.push_back(max(nums[2 * i], nums[2 * i + 1]));
                }
            }
            nums = tmp;
            n /= 2;
        }
        return nums[0];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
