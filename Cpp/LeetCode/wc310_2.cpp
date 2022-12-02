#include "usual.h"

class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        vector<bool> vst(26);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vst[s[i] - 'a']) {
                ++ans;
                vst = vector<bool>(26);
            }
            vst[s[i] - 'a'] = true;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
