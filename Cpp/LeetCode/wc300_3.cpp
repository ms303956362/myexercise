#include "usual.h"

class Solution {
    using ll = long long;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> add(n), minus(n);
        ll mod = 1e9 + 7;
        add[0] = 1;
        if (forget < n) {
            minus[forget] = -1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + delay; j < n && j < i + forget; ++j) {
                add[j] = (add[i] + add[j]) % mod;
                if (j + forget < n) {
                    minus[j + forget] = -add[j];
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + add[i] + minus[i]) % mod;
            if (ans < 0) {
                ans = (ans + ((-ans) / mod + 1) * mod) % mod;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
