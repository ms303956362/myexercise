#include "usual.h"

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        if (st.size() < 3) {
            return -1;
        }
        return *next(st.begin());
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
