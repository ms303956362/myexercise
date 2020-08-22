#include "usual.h"

class Solution {
public:
    int minInsertions(string s) {
        int cntl = 0, addl = 0, cntr = 0, addr = 0;
        for (const auto& c : s) {
            if (c == '(') {
                if (cntr == 0)
                    ++cntl;
                else if (cntr == 1) {
                    if (cntl == 0) {
                        ++addl;
                        ++cntl;
                    }
                    ++addr;
                    cntr = 0;
                } // cntr >= 2 shouldn't occur
            } else {
                if (cntr == 0)
                    ++cntr;
                else if (cntr == 1) {
                    if (cntl == 0) {
                        ++addl;
                        ++cntl;
                    }
                    --cntl;
                    cntr = 0;
                }
            }
        }
        if (cntl == 0 && cntr != 0) {
            ++addl;
            ++addr;
        } else if (cntl != 0) {
            addr += 2 * cntl - cntr;
        }
        return addl + addr;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
