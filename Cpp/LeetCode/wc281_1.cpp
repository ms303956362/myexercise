#include "usual.h"

class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 1; i <= num; ++i) {
            int tmp = i, s = 0;
            while (tmp > 0) {
                s += tmp % 10;
                tmp /= 10;
            }
            if (s % 2 == 0) {
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
