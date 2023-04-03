#include "usual.h"

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        long long ans  = 0;
        for (const auto& s : strs) {
            bool ok = true;
            for (const auto& c : s) {
                if (!('0' <= c && c <= '9')) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = max(ans, stoll(s));
            } else {
                ans = max(ans, (long long)s.size());
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
