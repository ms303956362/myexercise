#include "usual.h"

class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0)
            return "0";
        int i = 0;
        string s;
        while (n > 0) {
            if (i != 0 && i % 3 == 0)
                s.push_back('.');
            s.push_back(n % 10 + '0');
            ++i;
            n /= 10;
        }
        return string(s.rbegin(), s.rend());
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
