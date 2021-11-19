#include "usual.h"

class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnt1 = 0, cnt2 = 0, n = colors.size();
        for (int i = 1; i < n - 1; ++i) {
            if (colors[i] == 'A' && colors[i - 1] == 'A' && colors[i + 1] == 'A')
                ++cnt1;
            if (colors[i] == 'B' && colors[i - 1] == 'B' && colors[i + 1] == 'B')
                ++cnt2;
        }
        return cnt1 > cnt2;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
