#include "usual.h"

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans = 0;
        while ((a > 0 && b > 0) || (a > 0 && c > 0) || (b > 0 && c > 0)) {
            if (a >= b && a >= c) {
                --a;
                if (b >= c)
                    --b;
                else
                    --c;
            } else if (b >= c) {
                --b;
                if (a >= c)
                    --a;
                else
                    --c;
            } else {
                --c;
                if (a >= b)
                    --a;
                else
                    --b;
            }
            ++ans;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
