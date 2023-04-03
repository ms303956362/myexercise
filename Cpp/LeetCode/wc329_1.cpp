#include "usual.h"

class Solution {
public:
    int alternateDigitSum(int n) {
        int ans = 0;
        vector<int> v;
        while (n > 0) {
            v.push_back(n % 10);
            n /= 10;
        }
        int l = v.size(), sgn = 1;
        for (int i = l - 1; i >= 0; --i) {
            ans += sgn * v[i];
            sgn = -sgn;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
