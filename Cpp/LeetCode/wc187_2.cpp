#include "usual.h"

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        if (k == 0)
            return true;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i != k; ++i) {
            sum += nums[i];
        }
        if (k == n) {
            return sum > 1 ? false : true;
        }
        for (int i = 0, j = k; j != n; ++i, ++j){
            sum += nums[j];
            if (sum > 1)
                return false;
            sum -= nums[i];
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
