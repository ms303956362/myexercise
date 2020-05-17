#include "usual.h"

class Solution {
public:
    string arrangeWords(string text) {
        vector<string> vs;
        int i = 1, j = 0, n = text.size();
        text[0] = text[0] - 'A' + 'a';
        while (i != n) {
            if (text[i] == ' ') {
                vs.push_back(text.substr(j, i - j));
                j = i + 1;
            }
            ++i;
        }
        vs.push_back(text.substr(j, i - j));
        stable_sort(vs.begin(), vs.end(), [](const string &ls, const string &rs) { return ls.size() < rs.size(); });
        string res = vs[0];
        for (int k = 1; k != vs.size(); ++k) {
            res = res + " " + vs[k];
        }
        res[0] = res[0] - 'a' + 'A';
        return res;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().arrangeWords("Leetcode is cool") << endl;
    return 0;
}
