#include "usual.h"

class Solution {
public:
    int countHomogenous(string s) {
        long long MOD = 1e9 + 7;
        long long l = 0, r = 1, n = s.size();
        long long ans = 0;
        if (n == 1)
            return 1;
        while (r < n) {
            if (s[r] == s[r - 1]) {
                ++r;
            } else {
                ans += (r - l) * (r - l + 1) / 2;
                ans %= MOD;
                l = r;
                ++r;
            }
        }
        ans += (r - l) * (r - l + 1) / 2;
        ans %= MOD;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
