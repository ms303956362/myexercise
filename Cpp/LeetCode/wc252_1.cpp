#include "usual.h"

class Solution {
public:
    bool isThree(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i * (n / i) == n)
                ++ans;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
