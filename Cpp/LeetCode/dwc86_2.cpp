#include "usual.h"

class Solution {
public:
    bool check(int n, int b) {
        string s;
        while (n > 0) {
            s.push_back(n % b + '0');
            n /= b;
        }
        string t(s.rbegin(), s.rend());
        return s == t;
    }

    bool isStrictlyPalindromic(int n) {
        for (int b = 2; b <= n - 2; ++b) {
            if (!check(n, b)) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
