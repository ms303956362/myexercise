#include "usual.h"

class Solution {
public:
    bool isPrefix(const string& w, const string&s) {
        if (w.size() > s.size()) {
            return false;
        }
        return w == s.substr(0, w.size());
    }

    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for (const auto &w : words) {
            if (isPrefix(w, s)) {
                ++cnt;
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
