#include "usual.h"

class Solution {
public:
    int minOperations(string s) {
        bool is1 = false;
        int ans1 = 0;
        for (const auto& c : s) {
            if (is1) {
                if (c == '0')
                    ++ans1;
                is1 = false;
            } else {
                if (c == '1')
                    ++ans1;
                is1 = true;
            }
        }
        is1 = true;
        int ans2 = 0;
        for (const auto& c : s) {
            if (is1) {
                if (c == '0')
                    ++ans2;
                is1 = false;
            } else {
                if (c == '1')
                    ++ans2;
                is1 = true;
            }
        }
        return min(ans1, ans2);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
