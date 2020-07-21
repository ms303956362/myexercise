#include "usual.h"

class Solution {
public:
    int numWaterBottles(int b, int a) {
        int l = 0, res = 0;
        while (b >= a) {
            res += b;
            b = (b + l) / a;
            l = (b + l) % a;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
