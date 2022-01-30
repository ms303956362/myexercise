#include "usual.h"

class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') {
                for (int j = 0; j < i; ++j) {
                    if (s[j] == 'b')
                        return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
