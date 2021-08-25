#include "usual.h"

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string ss;
        for (const auto& w : words) {
            ss += w;
            if (s == ss)
                return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
