#include "usual.h"

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int i = 0, j = x, n = nums.size();
        set<int> st;
        int ans = INT_MAX;
        while (j < n) {
            st.insert(nums[i]);
            auto p = st.lower_bound(nums[j]);
            if (p != st.end()) {
                ans = min(ans, abs(*p - nums[j]));
            }
            if (p != st.begin()) {
                auto q = prev(p);
                ans = min(ans, abs(*q - nums[j]));
            }
            ++i;
            ++j;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
