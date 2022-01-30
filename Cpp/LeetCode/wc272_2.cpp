#include "usual.h"

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int n = s.size(), m = spaces.size(), beg = 0;
        for (int i = 0; i < m; ++i) {
            int end = spaces[i];
            ans += s.substr(beg, end - beg);
            ans.push_back(' ');
            beg = end;
        }
        ans += s.substr(beg, n - beg);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
