#include "usual.h"

class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for (int i = 1; i < n; i += 2) {
            ans += n - i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
