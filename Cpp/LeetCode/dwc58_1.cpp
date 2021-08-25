#include "usual.h"

class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        for (int i = 0; i < s.size(); ++i)
            if (i == 0 || i == 1 || !(s[i] == s[i - 1] && s[i] == s[i - 2]))
                ans.push_back(s[i]);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
