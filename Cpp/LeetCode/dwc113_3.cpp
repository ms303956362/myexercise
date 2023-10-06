#include "usual.h"

class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        long long n = coordinates.size();
        unordered_map<long long, long long> cnt;
        long long ans = 0;
        auto pair2ll = [](long long x, long long y) {
            return x * 1e8 + y;
        };
        for (int i = n - 1; i >= 0; --i) {
            for (int x = 0; x <= k; ++x) {
                int y = k - x;
                long long l = pair2ll(x ^ coordinates[i][0], y ^ coordinates[i][1]);
                ans += cnt[l];
            }
            ++cnt[pair2ll(coordinates[i][0], coordinates[i][1])];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
