#include "usual.h"

class Solution {
    using ll = long long;

public:
    int maximumCandies(vector<int>& candies, long long k) {
        ll l = 1, h = 1e8;
        while (l <= h) {
            ll m = (l + h) / 2;
            ll sum = 0;
            for (const long long& c : candies) {
                sum += c / m;
            }
            if (sum >= k) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return h;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
