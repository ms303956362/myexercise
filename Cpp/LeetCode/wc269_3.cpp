#include "usual.h"

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int i_max = max_element(nums.begin(), nums.end()) - nums.begin(), i_min = min_element(nums.begin(), nums.end()) - nums.begin();
        int i = max(i_max, i_min), j = min(i_max, i_min);
        return min({i, n - j, j + n - i});
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
