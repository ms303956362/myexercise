#include "usual.h"

class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, ans = 0;
        for (const auto& c : s) {
            if (c == '(') {
                ++cnt;
            } else if (c == ')') {
                ans = max(ans, cnt);
                --cnt;
            }  
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
