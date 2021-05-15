#include "usual.h"

class Solution {
    int up;

public:
    bool checkPowersOfThree(int n) {
        up = 1e7 + 5;
        return backtrack(1, 1, 0, n);
    }

    bool backtrack(int curr, int x, int i, int n) {
        if (curr > up || i == 20) {
            return curr == n;
        }
        x *= 3;
        if (backtrack(curr, x, i + 1, n))
            return true;
        if (backtrack(curr * x, x, i + 1, n))
            return true;
        return false;
    }
};