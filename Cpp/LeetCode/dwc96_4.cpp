#include "usual.h"

class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        while (targetX % 2 == 0) {
            targetX /= 2;
        }
        while (targetY % 2 == 0) {
            targetY /= 2;
        }
        return targetX == 1 || targetY == 1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
