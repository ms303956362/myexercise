#include "usual.h"

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int diff = INT_MAX, ans = INT_MIN;
        for (const auto& num : nums) {
            if (abs(num) < diff || abs(num) == diff && num > ans) {
                diff = abs(num);
                ans = num;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
