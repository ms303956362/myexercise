#include "usual.h"

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> st(nums.begin(), nums.end());
        int n = moveFrom.size();
        for (int i = 0; i < n; ++i) {
            st.erase(moveFrom[i]);
            st.insert(moveTo[i]);
        }
        return vector<int>(st.begin(), st.end());
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
