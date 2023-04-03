#include "usual.h"

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0, h = 1e15;
        long long ans = 0;
        int n = ranks.size();
        while (l <= h) {
            long long m = (l + h) / 2;
            long long cnt = 0;
            for (int i = 0; i < n; ++i) {
                long long k = sqrt((double)m / ranks[i]);
                long long add = 0;
                for (long long j = k - 2; j <= k + 2; ++j) {
                    if (ranks[i] * j * j <= m) {
                        add = j;
                    }
                }
                cnt += add;
            }
            if (cnt >= cars) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
