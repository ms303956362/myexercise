#include "usual.h"

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long l = 1, h = 1000000;
        while (l <= h) {
            long long m = (l + h) / 2, s = 2 * m * (m + 1) * (2 * m + 1);
            if (s > neededApples)
                h = m - 1;
            else if (s < neededApples)
                l = m + 1;
            else
                return 8 * m;
        }
        return 8 * l;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
