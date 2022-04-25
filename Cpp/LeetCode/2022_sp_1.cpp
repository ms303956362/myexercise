#include "usual.h"

class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (const auto& op : operations) {
            int num = gem[op[0]];
            gem[op[0]] -= num / 2;
            gem[op[1]] += num / 2;
        }
        int max_gem = 0, min_gem = INT_MAX;
        for (const auto& g : gem) {
            max_gem = max(max_gem, g);
            min_gem = min(min_gem, g);
        }
        return max_gem - min_gem;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
