#include "usual.h"

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int wa = capacityA, wb = capacityB;
        int n = plants.size(), ans = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            if (wa < plants[i]) {
                wa = capacityA;
                ++ans;
            }
            if (wb < plants[j]) {
                wb = capacityB;
                ++ans;
            }
            wa -= plants[i];
            wb -= plants[j];
            ++i;
            --j;
        }
        if (i == j) {
            if (wa >= wb) {
                if (wa < plants[i]) {
                    ++ans;
                }
            } else {
                if (wb < plants[j])
                    ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
