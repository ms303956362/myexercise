#include "usual.h"

class Solution {
public:
    string modifyString(string s) {
        string ans(s);
        int n = s.size();
        for (int i = 0; i != n; ++i) {
            if (ans[i] == '?') {
                for (char c = 'a'; c <= 'z'; ++c) {
                    if ((i == 0 || ans[i - 1] != c) && (i == n || ans[i + 1] != c)) {
                        ans[i] = c;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
