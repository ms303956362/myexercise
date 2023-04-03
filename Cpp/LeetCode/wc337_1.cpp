#include "usual.h"

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        for (int i = 0; i < 16; ++i) {
            ans[i % 2] += ((n & (1 << i)) != 0);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
