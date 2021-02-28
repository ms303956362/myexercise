#include "usual.h"

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        for (int i = 0; i != n; ++i) {
            int l = i, r = i;
            while (0 <= l && r < n) {
                if (s[l] == s[r])
                    isPalin[l][r] = true;
                --l;
                ++r;
            }
            l = i, r = i + 1;
            while (0 <= l && r < n) {
                if (s[l] == s[r])
                    isPalin[l][r] = true;
                --l;
                ++r;
            }
        }
        for (int i = 0; i != n - 2; ++i) {
            for (int j = i + 1; j != n - 1; ++j) {
                if (isPalin[0][i] && isPalin[i + 1][j] && isPalin[j + 1][n - 1])
                    return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
