#include "usual.h"

class Solution {
public:
    bool checkZeroOnes(string s) {
        int l1 = 0, l0 = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[j] != s[i]) {
                    break;
                }
            }
            if (s[i] == '1')
                l1 = max(l1, j - i);
            else
                l0 = max(l0, j - i);
        }
        return l1 > l0;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
