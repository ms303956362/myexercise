#include "usual.h"

class Solution {
public:
    int sumBase(int n, int k) {
        int ans = 0;
        while (n > 0) {
            ans += n % k;
            n /= k;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
