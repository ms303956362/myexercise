#include "usual.h"
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        multiset<int> st(nums.begin(), nums.end());
        unordered_set<int> ss;
        while (st.size() > 0) {
            int num1 = *st.rbegin();
            st.erase(prev(st.end()));
            int num2 = *st.begin();
            st.erase(st.begin());
            ss.insert(num1 + num2);
        }
        return ss.size();
    }
};