#include "usual.h"

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        bool ok = false;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (prices[i] + prices[j] <= money) {
                    ok = true;
                    ans = max(ans, money - prices[i] - prices[j]);
                }
            }
        }
        return ok ? ans : money;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
