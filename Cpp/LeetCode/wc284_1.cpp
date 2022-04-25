#include "usual.h"

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            bool ok = false;
            for (int j = max(0, i - k); j < min(n, i + k + 1); ++j) {
                if (nums[j] == key) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
