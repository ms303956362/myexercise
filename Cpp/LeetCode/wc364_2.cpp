#include "usual.h"

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ans = 0;
        int n = maxHeights.size();
        auto check = [&](int i) -> long long {
            long long sum = maxHeights[i], nh = maxHeights[i];
            for (int j = i - 1; j >= 0; --j) {
                long long h = min((long long)maxHeights[j], nh);
                sum += h;
                nh = h;
            }
            nh = maxHeights[i];
            for (int j = i + 1; j < n; ++j) {
                long long h = min((long long)maxHeights[j], nh);
                sum += h;
                nh = h;
            }
            return sum;
        };
        for (int i = 0; i < n; ++i) {
            ans = max(ans, check(i));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
