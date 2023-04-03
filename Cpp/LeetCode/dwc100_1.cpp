#include "usual.h"

class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        money -= children;
        int ans = 0;
        while (money > 0 && ans < children) {
            if (money >= 7) {
                ++ans;
                money -= 7;
            } else {
                if (money == 3 && children - ans == 1) {
                    --ans;
                }
                money = 0;
            }
        }
        if (money > 0) {
            --ans;
        }
        return max(ans, 0);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
