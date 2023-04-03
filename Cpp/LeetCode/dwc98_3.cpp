#include "usual.h"

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        set<long long> st(nums.begin(), nums.end());
        long long ans = 1;
        while (st.count(ans)) {
            ans *= 2;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
