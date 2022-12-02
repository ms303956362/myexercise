#include "usual.h"

class Solution {
public:
    int countAsterisks(string s) {
        int n = s.size(), cnt = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '|') {
                ++cnt;
            }
            if (cnt % 2 == 0 && s[i] == '*') {
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
