#include "usual.h"

class Solution {
public:
    int countDigits(int num) {
        int tmp = num;
        int ans = 0;
        while (tmp > 0) {
            if (num % (tmp % 10) == 0) {
                ++ans;
            }
            tmp /= 10;
        }
        return ans;
    }
};