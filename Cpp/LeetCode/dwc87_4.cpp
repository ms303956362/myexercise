#include "usual.h"

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long co_cb_sum = 0, co_max_neg = -1, cb_max_pos = -1;
        vector<pair<long long, long long>> v;
        for (const auto& t : transactions) {
            long long co = t[0], cb = t[1];
            if (co > cb) {
                co_cb_sum += co - cb;
                cb_max_pos = max(cb_max_pos, cb);
            } else {
                co_max_neg = max(co_max_neg, co);
            }
        }
        long long ans = 0;
        if (co_max_neg > -1) {
            ans = max(ans, co_cb_sum + co_max_neg);
        }
        if (cb_max_pos > -1) {
            ans = max(ans, co_cb_sum + cb_max_pos);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
