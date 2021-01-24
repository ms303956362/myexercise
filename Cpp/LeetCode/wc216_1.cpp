#include "usual.h"

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for (const auto& s : word1) {
            s1 += s;
        }
        for (const auto& s : word2) {
            s2 += s;
        }
        return s1 == s2;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
