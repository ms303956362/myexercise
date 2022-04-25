#include "usual.h"

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        for (char c = s[0]; c <= s[3]; ++c) {
            for (char n = s[1]; n <= s[4]; ++n) {
                ans.push_back(string(1, c) + string(1, n));
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
