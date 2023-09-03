#include "usual.h"

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        set<int> st(nums.begin(), nums.end());
        int total = st.size();
        for (int i = 0; i < n; ++i) {
            vector<int> cnt(2005);
            int diff = 0;
            for (int j = i; j < n; ++j) {
                if (cnt[nums[j]] == 0) {
                    ++diff;
                }
                ++cnt[nums[j]];
                if (diff == total) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
