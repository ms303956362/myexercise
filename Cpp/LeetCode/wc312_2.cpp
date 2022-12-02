#include "usual.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), max_num = *max_element(nums.begin(), nums.end());
        int i = 0, ans = 1;
        while (i < n) {
            if (nums[i] != max_num) {
                ++i;
            } else {
                int j = i + 1;
                while (j < n && nums[j] == max_num) {
                    ++j;
                }
                ans = max(ans, j - i);
                i = j;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
