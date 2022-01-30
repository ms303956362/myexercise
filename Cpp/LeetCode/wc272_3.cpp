#include "usual.h"

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long i = 0, j = 0, n = prices.size();
        long long ans = 0;
        while (i < n) {
            j = i + 1;
            while (j < n && prices[j] - prices[j - 1] == -1)
                ++j;
            long long l = j - i;
            ans += (1 + l) * l / 2;
            i = j;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
