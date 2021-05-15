#include "usual.h"

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int sum1 = 0, sum2 = 0;
        for (const auto& num :arr1)
            sum1 ^= num;
        for (const auto& num :arr2)
            sum2 ^= num;
        return sum1 & sum2;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
