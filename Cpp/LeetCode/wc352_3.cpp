#include "usual.h"

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        multiset<int> st;
        long long i = 0, j = 0, ans = 0;
        while (i < n) {
            st.insert(nums[i]);
            while (j < i && *st.rbegin() - *st.begin() > 2) {
                st.extract(nums[j]);
                ++j;
            }
            ans += i - j + 1;
            ++i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{5,4,2,4};
    Solution().continuousSubarrays(a);
    return 0;
}
