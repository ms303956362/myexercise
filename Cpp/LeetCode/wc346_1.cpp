#include "usual.h"

class Solution {
public:
    int minLength(string s) {
        string last = s;
        auto trim = [](string& s) {
            int n = s.size();
            string t;
            for (int i = 0; i < n; ++i) {
                if (i < n && ((s[i] == 'A' && s[i + 1] == 'B') || (s[i] == 'C' && s[i + 1] == 'D'))) {
                    ++i;
                } else {
                    t.push_back(s[i]);
                }
            }
            s = t;
        };
        while (true) {
            last = s;
            trim(s);
            if (s == last) {
                break;
            }
        }
        return s.size();
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
