#include "usual.h"

class Solution {
public:
    int numWays(string s) {
        long long MOD = 1e9 + 7;
        long long n = s.size();
        long long cnt = 0;
        for (int i = 0; i != n; ++i) {
            if (s[i] == '1')
                ++cnt;
        }
        if (cnt == 0)
            return ((n - 1) * (n - 2) /  2) % MOD;
        if (cnt % 3 != 0)
            return 0;
        long long cnt1 = 0, cnt01 = 0, cnt02 = 0;
        bool f1 = false, f2 = false;
        for (int i = 0; i != n; ++i) {
            if (s[i] == '1') {
                ++cnt1;
                if (f1)
                    f1 = false;
                if (f2)
                    f2 = false;
                if (cnt1 == cnt / 3)
                    f1 = true;
                else if (cnt1 == 2 * cnt / 3)
                    f2 = true;
            } else {
                if (f1)
                    ++cnt01;
                if (f2)
                    ++cnt02;
            }
        }
        return (cnt01 + 1) * (cnt02 + 1) % MOD;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
