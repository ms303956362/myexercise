#include "usual.h"

class Solution {
public:
    int minCount(vector<int>& coins) {
        int s = 0;
        for (auto& c :coins) {
            s += c / 2 + c % 2;
        }
        return s;
    }
};