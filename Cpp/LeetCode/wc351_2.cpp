#include "usual.h"

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long n1 = num1, n2 = num2;
        auto bits = [](long long num) {
            int ret = 0;
            while (num > 0) {
                ret += (num & 1);
                num >>= 1;
            }
            return ret;
        };
        for (long long k = 1; k <= 100; ++k) {
            if (n1 - k * n2 >= k && bits(n1 - k * n2) <= k) {
                // cout << n1 - k * n2 << " " << bits(n1 - k * n2) << " " << k << endl;
                return k;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    int n1 = 112577768, n2 = -501662198;
    Solution().makeTheIntegerZero(n1, n2);
    return 0;
}
