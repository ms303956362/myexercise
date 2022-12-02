#include "usual.h"

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        auto rev = [](int num) {
            int ret = 0;
            while (num > 0) {
                ret = ret * 10 + num % 10;
                num /= 10;
            }
            return ret;
        };
        for (int i = 0; i < n; ++i) {
            nums.push_back(rev(nums[i]));
        }
        return unordered_set<int>(nums.begin(), nums.end()).size();
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
