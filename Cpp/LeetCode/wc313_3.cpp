#include "usual.h"

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n1 = __builtin_popcount(num1), n2 = __builtin_popcount(num2);
        if (n1 == n2) {
            return num1;
        }
        int ans = 0;
        if (n1 < n2) {
            int n = n2 - n1, j = 0;
            ans = num1;
            for (int i = 0; i < n; ++i) {
                while (num1 & 1) {
                    num1 >>= 1;
                    ++j;
                }
                ans |= (1 << j);
            }
        } else {
            int n = n1 - n2, j = 0;
            ans = num1;
            for (int i = 0; i < n; ++i) {
                while (num1 & 0) {
                    num1 >>= 1;
                    ++j;
                }
                ans &= ~(1 << j);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
