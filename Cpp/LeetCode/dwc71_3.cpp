#include "usual.h"

class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        auto cal = [&](vector<int> &t)
        {
            int i = 0;
            while (i < 4 && t[i] == 0) {
                ++i;
            }
            int ret = 0;
            bool first = true;
            while (i < 4) {
                if (first) {
                    if (t[i] != startAt) {
                        ret += moveCost;
                    }
                } else {
                    if (t[i] != t[i - 1]) {
                        ret += moveCost;
                    }
                }
                // if ((first && t[i] != startAt) || (i > 0 && t[i] != t[i - 1])) {
                //     ret += moveCost;
                // }
                ret += pushCost;
                first = false;
                ++i;
            }
            return ret;
        };
        int minutes = targetSeconds / 60, seconds = targetSeconds % 60;
        int ans = INT_MAX;
        if (minutes < 100) {
            vector<int> v1{minutes / 10, minutes % 10, seconds / 10, seconds % 10};
            ans = min(ans, cal(v1));
        }
        if (minutes > 0 && seconds < 40) {
            --minutes;
            seconds += 60;
            vector<int> v2{minutes / 10, minutes % 10, seconds / 10, seconds % 10};
            ans = min(ans, cal(v2));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution().minCostSetTime(1, 1, 1, 1);
    return 0;
}
