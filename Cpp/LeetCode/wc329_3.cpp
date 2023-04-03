#include "usual.h"

class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        if (s == t) {
            return true;
        }
        int n = s.size(), cnts = 0, cntt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++cnts;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (t[i] == '1') {
                ++cntt;
            }
        }
        return cnts >= 1 && cntt >= 1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
