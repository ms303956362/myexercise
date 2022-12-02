#include "usual.h"

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> tab;
        char t = 'a';
        for (const auto& c : key) {
            if (c == ' ') {
                continue;
            }
            if (tab.count(c)) {
                continue;
            }
            tab[c] = t;
            ++t;
            if (t > 'z') {
                break;
            }
        }
        string ans;
        for (const auto& c : message) {
            if (tab.count(c)) {
                ans.push_back(tab[c]);
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
