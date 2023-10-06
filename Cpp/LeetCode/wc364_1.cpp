#include "usual.h"

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0, n = s.size();
        for (const auto& c : s) {
            if (c == '1') {
                ++cnt;
            }
        }
        string ans;
        for (int i = 0; i < cnt - 1; ++i) {
            ans.push_back('1');
        }
        for (int i = 0; i < n - cnt; ++i) {
            ans.push_back('0');
        }
        ans.push_back('1');
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
