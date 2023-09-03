#include "usual.h"

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            set<int> s1, s2;
            for (int j = 0; j <= i; ++j) {
                s1.insert(nums[j]);
            }
            for (int j = i + 1; j < n; ++j) {
                s2.insert(nums[j]);
            }
            ans[i] = (int)s1.size() - (int)s2.size();
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
