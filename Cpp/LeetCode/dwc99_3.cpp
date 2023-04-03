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
    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size(), m = 0;
        sort(ranges.begin(), ranges.end());
        int i = 0;
        while (i < n) {
            int max_r = ranges[i][1], j = i + 1;
            while (j < n && ranges[j][0] <= max_r) {
                max_r = max(max_r, ranges[j][1]);
                ++j;
            }
            i = j;
            ++m;
        }
        return pow(2, m, 1e9 + 7);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
