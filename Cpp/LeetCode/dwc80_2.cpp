#include "usual.h"

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int n = potions.size();
        for (long long s : spells) {
            if (success % s == 0) {
                ans.push_back(potions.end() - lower_bound(potions.begin(), potions.end(), success / s));
            } else {
                ans.push_back(potions.end() - upper_bound(potions.begin(), potions.end(), success / s));
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
