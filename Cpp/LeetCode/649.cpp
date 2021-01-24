#include "usual.h"


class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        if (n == 1)
            return senate == "R" ? "Radiant" : "Dire";
        int cnt_r = 0, cnt_d = 0;
        for (const auto& c :senate) {
            int &cnt = (c == 'R' ? cnt_r :cnt_d);
            ++cnt;
        }
        char me = senate[0], op = (me == 'R' ? 'D' : 'R');
        int rnow = 0, dnow = 0;
        vector<bool> exist(n, true);
        for (int i = 0; cnt_r > 0 && cnt_d > 0; ) {
            int &now0 = (senate[i] == 'R' ? rnow : dnow), &now1 = (senate[i] == 'R' ? dnow : rnow);
            int &cnt0 = (senate[i] == 'R' ? cnt_r : cnt_d), &cnt1 = (senate[i] == 'R' ? cnt_d : cnt_r);
            while (senate[i] == me) {
                if (exist[i]) {
                    if (now1) {
                        exist[i] = false;
                        --cnt0;
                        --now1;
                    } else {
                        ++now0;
                    }
                }
                i = (i + 1) % n;
            }
            swap(me, op);
        }
        return (cnt_d > 0 ? "Dire" : "Radiant");
    }
};

int main(int argc, char const *argv[])
{
    string s = "RD";
    Solution().predictPartyVictory(s);
    return 0;
}
