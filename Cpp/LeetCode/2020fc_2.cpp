#include "usual.h"

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        int ans = 0, MOD = 1e9 + 7;
        for (int i = 0; i != staple.size(); ++i) {
            if (staple[i] > x)
                break;
            auto p = upper_bound(drinks.begin(), drinks.end(), x - staple[i]);
            ans = (ans + p - drinks.begin()) % MOD;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
