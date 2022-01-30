#include "usual.h"

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for (auto& num : nums) {
            if (num == original) {
                num *= 2;
                original = num;
            }
        }
        return original;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
