#include "usual.h"

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_s = nums[0];
        int sum = 0;
        int ret = 1;
        for (auto& n : nums) {
            sum += n;
            if (sum < min_s)
                min_s = sum;
        }
        if (min_s <= 0)
            ret = 1 - min_s;
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
