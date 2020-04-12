#include "usual.h"

class Solution {
public:
    string entityParser(string text0) {
        unordered_map<string, char> table{
            {"&quot;", '"'},
            {"&apos;", '\''},
            {"&amp;", '&'},
            {"&gt;", '>'},
            {"&lt;", '<'},
            {"&frasl;", '/'},
        };
        list<char> text(text0.begin(), text0.end());
        decltype(text.begin()) beg = text.end(), end = text.begin();
        int idx = 0, bi = text.size(), ei = 0;
        for (auto p = text.begin(); p != text.end(); ++p) {
            ++idx;
            if (*p == '&') {
                beg = p;
                bi = idx;
            }
            else if (*p == ';') {
                auto pp = p;
                end = ++pp;
                ei = idx + 1;
                if (ei - bi > 0) {
                    string q(beg, end);
                    auto pc = table.find(q);
                    if (pc != table.end()) {
                        auto p_del = text.erase(beg, end);
                        p = text.insert(p_del, pc->second);
                    }
                }
                beg = text.end();
                end = text.begin();
            }
        }
        return string(text.begin(), text.end());
    }
};

int main(int argc, char const *argv[])
{
    string s = "&amp; is an HTML entity but &ambassador; is not.";
    cout << Solution().entityParser(s) << endl;
    return 0;
}
