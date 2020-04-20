#include "usual.h"

class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        int nd = increase.size() + 1, nr = requirements.size();
        vector<int> vc(nd,0), vr(nd,0), vh(nd,0);
        for (int i = 1; i != nd; ++i) {
            vc[i] = increase[i - 1][0] + vc[i - 1];
            vr[i] = increase[i - 1][1] + vr[i - 1];
            vh[i] = increase[i - 1][2] + vh[i - 1];
        }
        vector<int> res(nr, -1);
        for (int i = 0; i != nr; ++i) {
            auto pc = lower_bound(vc.begin(), vc.end(), requirements[i][0]);
            if (pc == vc.end())
                continue;
            int lc = pc - vc.begin();
            auto pr = lower_bound(vr.begin() + lc, vr.end(), requirements[i][1]);
            if (pr == vr.end())
                continue;
            int lr = pr - vr.begin();
            auto ph = lower_bound(vh.begin() + lr, vh.end(), requirements[i][2]);
            if (ph != vh.end())
                res[i] = ph - vh.begin();
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> vi{{2, 8, 4}, {2, 5, 0}, {10, 9, 8}}, vr{{2, 11, 3}, {15, 10, 7}, {9, 17, 12}, {8, 1, 14}};
    Solution().getTriggerTime(vi, vr);
    return 0;
}