#include "usual.h"

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        long long mod = 1e9 + 7, mask = 1;
        vector<long long> power;
        while (n > 1) {
            if (n & 1) {
                power.push_back(mask);
            }
            n >>= 1;
            mask = (mask * 2) % mod;
        }
        vector<int> ans;
        for (const auto& q : queries) {
            long long prod = 1;
            for (int i = q[0]; i <= q[1]; ++i) {
                prod = (prod * power[i]) % mod;
            }
            ans.push_back(prod % mod);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
