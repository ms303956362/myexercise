#include "usual.h"

class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'X') {
                s[i] = 'O';
                if (i + 1 < n)
                    s[i + 1] = 'O';
                if (i + 2 < n)
                    s[i + 2] = 'O';
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
