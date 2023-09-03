#include "usual.h"

class Solution {
public:
    string removeTrailingZeros(string num) {
        while (!num.empty() && num.back() == '0') {
            num.pop_back();
        }
        return num;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
