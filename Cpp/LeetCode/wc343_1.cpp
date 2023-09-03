#include "usual.h"

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        auto calc = [](vector<int>& v) {
            int n = v.size(), sum = 0;
            for (int i = 0; i < n; ++i) {
                if ((i > 0 && v[i - 1] == 10) || (i > 1 && v[i - 2] == 10)) {
                    sum += 2 * v[i];
                } else {
                    sum += v[i];
                }
            }
            return sum;
        };
        int s1 = calc(player1), s2 = calc(player2);
        if (s1 == s2) {
            return 0;
        } else if (s1 > s2) {
            return 1;
        }
        return 2;
    }
};
