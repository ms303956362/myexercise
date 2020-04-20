#include "usual.h"

class Solution {
public:
    string reformat(string s) {
        string s1, s2;
        for (auto& c: s) {
            if ('a' <= c && c <= 'z')
                s1 += c;
            else if ('0' <= c && c <= '9')
                s2 += c;
        }
        string s_max = s1.size() > s2.size() ? s1 : s2, s_min = s1.size() > s2.size() ? s2 : s1;
        if (s_max.size() - s_min.size() > 1)
            return "";
        string ret;
        for (int i = 0, j = 0, k = 0; i != s.size(); ++i) {
            if (i % 2 == 0) {
                ret += s_max[j++];
            } else {
                ret += s_min[k++];
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().reformat("a") << endl;
    return 0;
}
