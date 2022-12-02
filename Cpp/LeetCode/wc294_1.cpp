#include "usual.h"

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size(), cnt = 0;
        for (const auto& c : s) {
            if (c == letter) {
                ++cnt;
            }
        }
        return 100 * cnt / n;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
