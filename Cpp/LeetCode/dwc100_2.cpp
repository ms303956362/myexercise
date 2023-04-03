#include "usual.h"

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        multiset<int> st(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for (int i = n - 1; i >= 0; --i) {
            auto p = st.upper_bound(nums[i]);
            if (p != st.end()) {
                st.erase(p);
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
