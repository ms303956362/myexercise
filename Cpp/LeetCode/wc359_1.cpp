#include "usual.h"

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string t;
        for (const auto& w : words) {
            t.push_back(w[0]);
        }
        return s == t;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
