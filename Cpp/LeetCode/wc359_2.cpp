#include "usual.h"

class Solution {
public:
    int minimumSum(int n, int k) {
        if (k > 2 * n - 1) {
            return (1 + n) * n / 2;
        }
        int i = 1;
        int ans = (1 + n) * n / 2, b = n + 1;
        vector<int> a;
        while (i < k - i) {
            ans -= k - i;
            ans += b;
            ++b;
            ++i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
