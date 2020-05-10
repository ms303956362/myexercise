#include "usual.h"

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        vector<int> ans(366, 100000000);
        ans[0] = 0;
        days.insert(days.begin(), 0);
        int j = 0;
        for (int i = 1; i != days.size(); ++i) {
            for (j = i - 1; j > 0; --j) {
                if (days[j] <= days[i] - 1)
                    break;
            }
            ans[days[i]] = min(ans[days[i]], ans[days[j]] + cost[0]);
            for (j = i - 1; j > 0; --j) {
                if (days[j] <= days[i] - 7)
                    break;
            }
            ans[days[i]] = min(ans[days[i]], ans[days[j]] + cost[1]);
            for (j = i - 1; j > 0; --j) {
                if (days[j] <= days[i] - 30)
                    break;
            }
            ans[days[i]] = min(ans[days[i]], ans[days[j]] + cost[2]);
        }
        return ans[*days.rbegin()];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> days{1,2,3,4,5,6,7,8,9,10,30,31}, costs{2, 7, 15};
    cout << Solution().mincostTickets(days, costs) << endl;
    auto p = lower_bound(days.begin(), days.end(), 24);
    return 0;
}
