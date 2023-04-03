#include "usual.h"

class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        for (int i = 1; i < n; ++i) {
            ans += 4 * i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
