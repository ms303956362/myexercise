#include "usual.h"

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, pre(13);
        auto date2stamp = [&](const string& s) {
            int month = stoi(s.substr(0, 2)), day = stoi(s.substr(3, 2));
            return pre[month - 1] + day;
        };
        pre[0] = 0;
        for (int i = 1; i <= 12; ++i) {
            pre[i] = pre[i - 1] + days[i];
        }
        int s1 = date2stamp(arriveAlice), e1 = date2stamp(leaveAlice), s2 = date2stamp(arriveBob), e2 = date2stamp(leaveBob);
        int s = max(s1, s2), e = min(e1, e2);
        return max(e - s + 1, 0);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
