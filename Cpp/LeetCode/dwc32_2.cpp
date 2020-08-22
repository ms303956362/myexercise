#include "usual.h"

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size())
            return false;
        int m;
        vector<int> times(26, 0);
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] != t[i]) {
                m = (t[i] + 26 - s[i]) % 26;
                if (26 * times[m] + m <= k) {
                    ++times[m];
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
