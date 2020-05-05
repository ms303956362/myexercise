#include "usual.h"

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ret(n, true);
        int max_c = 0;
        for (auto& c : candies) {
            if (c > max_c)
                max_c = c;
        }
        for (int i = 0; i != n; ++i) {
            if (candies[i] + extraCandies > max_c)
                ret[i] = true;
            else
                ret[i] = false;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
