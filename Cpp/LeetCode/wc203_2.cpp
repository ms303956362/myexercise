#include "usual.h"

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int sum = 0;
        sort(piles.rbegin(), piles.rend());
        for (int i = 0; i != n / 3; ++i) {
            sum += piles[2 * i + 1];
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
