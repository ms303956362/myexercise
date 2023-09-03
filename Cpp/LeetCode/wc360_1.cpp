#include "usual.h"

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int cntl = 0, cntr = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (moves[i] == 'L') {
                ++cntl;
            } else if (moves[i] == 'R') {
                ++cntr;
            } else {
                ++cnt;
            }
        }
        return abs(cntr - cntl) + cnt;
    }
};