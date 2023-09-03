#include "usual.h"

class Solution {
public:
    int longestString(int x, int y, int z) {
        return min(2 * x + 2 * y, 4 * min(x, y) + 2) + 2 * z;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
