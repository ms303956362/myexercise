#include "usual.h"

class Solution {
public:
    int pivotInteger(int n) {
        for (int x = 1; x <= n; ++x) {
            int sum1 = 0, sum2 = 0;
            for (int i = 1; i <= x; ++i) {
                sum1 += i;
            }
            for (int i = x; i <= n; ++i) {
                sum2 += i;
            }
            if (sum1 == sum2) {
                return x;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
