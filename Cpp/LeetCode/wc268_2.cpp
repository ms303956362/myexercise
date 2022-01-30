#include "usual.h"

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0, water = capacity, n = plants.size();
        for (int i = 0; i < n; ++i) {
            if (water >= plants[i]) {
                water -= plants[i];
                ++ans;
            }
            else {
                ans += 2 * i + 1;
                water = capacity - plants[i];
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
