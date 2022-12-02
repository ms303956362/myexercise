#include "usual.h"

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        char c = 'a';
        for (int i = 0; i < n - 2; ++i) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                if (c == 'a' || num[i] > c) {
                    c = num[i];
                }
            }
        }
        return c == 'a' ? "" : string(3, c);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
