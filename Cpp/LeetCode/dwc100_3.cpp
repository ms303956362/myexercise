#include "usual.h"

class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<pair<long long, long long>> st;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            st.emplace(nums[i], i);
        }
        long long ans = 0;
        while (!st.empty()) {
            auto p = st.begin();
            ans += p->first;
            int i = p->second - 1, j = p->second + 1;
            st.erase(p);
            if (0 <= i && i < n && st.count(make_pair(nums[i], i))) {
                st.erase(make_pair(nums[i], i));
            }
            if (0 <= j && j < n && st.count(make_pair(nums[j], j))) {
                st.erase(make_pair(nums[j], j));
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
