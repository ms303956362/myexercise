#include "usual.h"

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) {
            return 0;
        }
        if (k == 0) {
            if (num % 10 != 0) {
                return -1;
            }
            return 1;
        }
        int ans = 0;
        while (num >= k) {
            num -= k;
            ++ans;
            if (num % 10 == 0) {
                return ans;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
