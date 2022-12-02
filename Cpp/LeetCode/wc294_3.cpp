#include "usual.h"

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if (n == 1) {
            return 0;
        }
        if (n == 2) {
            return 1;
        }
        sort(stockPrices.begin(), stockPrices.end());
        int ans = 1;
        long long xa = stockPrices[0][0], ya = stockPrices[0][1], xb = stockPrices[1][0], yb = stockPrices[1][1];
        for (int i = 2; i < n; ++i) {
            long long xc = stockPrices[i][0], yc = stockPrices[i][1];
            if ((xc - xa) * (yb - ya) != (xb - xa) * (yc - ya)) {
                ++ans;
            }
            xa = xb;
            ya = yb;
            xb = xc;
            yb = yc;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
