#include "usual.h"

class Solution {
public:
    string smallestString(string s) {
        int n = s.size(), i = 0;
        while (i < n && s[i] == 'a') {
            ++i;
        }
        if (i == n) {
            return s.substr(0, n - 1) + "z";
        }
        int j = i + 1;
        while (j < n && s[j] != 'a') {
            ++j;
        }
        for (int k = i; k < j; ++k) {
            --s[k];
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
