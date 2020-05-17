#include "usual.h"

class Solution {
public:
    int maxPower(string s) {
        char last = 'A';
        int cnt = 0, max_cnt = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == last) {
                ++cnt;
            } else {
                max_cnt = max(max_cnt, cnt);
                cnt = 1;
                last = s[i];
            }
        }
        return max_cnt;
    }
};