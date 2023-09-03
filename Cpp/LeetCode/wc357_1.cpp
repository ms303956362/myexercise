#include "usual.h"

class Solution {
public:
    string finalString(string s) {
        string ans;
        for (const auto& c : s) {
            if (c == 'i') {
                reverse(ans.begin(), ans.end());
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
