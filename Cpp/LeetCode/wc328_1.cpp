#include "usual.h"

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;
        for (const auto& num : nums) {
            sum1 += num;
            int tmp = num;
            while (tmp > 0) {
                sum2 += tmp % 10;
                tmp /= 10;
            }
        }
        return abs(sum1 - sum2);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
