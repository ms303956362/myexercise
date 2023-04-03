#include "usual.h"

class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long l = 1, h = 1e10;
        long long lcm = (long long)divisor1 * (long long)divisor2 / __gcd(divisor1, divisor2);
        auto check = [&](long long m) -> bool {
            long long c1 = m / divisor1, c2 = m / divisor2, cl = m / lcm;
            long long uc1 = max(uniqueCnt1 - (c2 - cl), 0LL), uc2 = max(uniqueCnt2 - (c1 - cl), 0LL);
            return m - c1 - c2 + cl >= uc1 + uc2;
        };
        long long ans = 1;
        while (l <= h) {
            long long m = (l + h) / 2;
            if (check(m)) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
