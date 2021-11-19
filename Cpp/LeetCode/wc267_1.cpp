#include "usual.h"

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(), ans = 0;
        for (int i = 0; tickets[k] > 0; i = (i + 1) % n) {
            if (tickets[i] == 0)
                continue;
            else {
                ++ans;
                --tickets[i];
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
