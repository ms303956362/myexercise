#include "usual.h"

using ll = long long;

ll pow(ll x, ll n, ll mod) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = (ret * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

class Solution {
public:

    int monkeyMove(int n) {
        ll mod = 1e9 + 7;
        return (pow(2, n, mod) - 2 + mod) % mod;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
