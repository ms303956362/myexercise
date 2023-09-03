#include "usual.h"

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while (mainTank > 0) {
            ans += 10;
            --mainTank;
            if (ans % 50 == 0 && additionalTank > 0) {
                --additionalTank;
                ++mainTank;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
