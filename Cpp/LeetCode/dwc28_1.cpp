#include "usual.h"

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.begin(), prices.end());
        for (int i = 0; i != ans.size() - 1; ++i) {
            for (int j = i + 1; j != ans.size(); ++j) {
                if (prices[j] <= prices[i]){
                    ans[i] = prices[i] - prices[j];
                    break;
                }
            }
        }
        return ans;
    }
};