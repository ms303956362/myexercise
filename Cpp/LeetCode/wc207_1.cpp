#include "usual.h"

class Solution {
public:
    string reorderSpaces(string text) {
        int cnt = 0, cnt_w = 0;
        for (int i = 0; i != text.size(); ++i) {
            if (text[i] == ' ')
                ++cnt;
            else if (text[i] != ' ' && (i == 0 || text[i - 1] == ' '))
                ++cnt_w;
        }
        int t = text.size() - 1;
        while (text[t] == ' ')
            --t;
        int num_sp = (cnt_w == 1 ? 0 : cnt / (cnt_w - 1)), end = (cnt_w == 1 ? cnt : cnt % (cnt_w - 1));
        bool has = false, ok = false;
        string res;
        for (int i = 0; i != t; ++i) {
            if (text[i] != ' ') {
                ok = false;
                has = true;
                res.push_back(text[i]);
            } else if (has && !ok){
                for (int k = 0; k != num_sp; ++k)
                    res.push_back(' ');
                ok = true;
            }
        }
        for (int k = 0; k != end; ++k)
            res.push_back(' ');
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution().reorderSpaces("  this   is  a sentence ");
    return 0;
}
