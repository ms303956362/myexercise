#include "usual.h"

class Solution {
public:
    int numSub(string s) {
        long long MOD = 1e9 + 7;
        long long i = 0, j = 0, n = s.size();
        long long ans = 0;
        while (i != n) {
            while (i != n && s[i] != '1')
                ++i;
            if (i == n)
                break;
            j = i;
            while (j != n && s[j] != '0')
                ++j;
            ans = (ans + ((j - i) * (j - i + 1) / 2) % MOD);
            i = j;
        }
        return (int)ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
