#include "usual.h"

class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans = 0;
        sort(amount.begin(), amount.end());
        while (amount[2] > 0) {
            --amount[2];
            if (amount[1] > 0) {
                --amount[1];
            }
            ++ans;
            sort(amount.begin(), amount.end());
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
