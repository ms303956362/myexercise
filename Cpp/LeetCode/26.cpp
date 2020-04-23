#include "usual.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();
        for (auto p1 = nums.begin(), p2 = ++nums.begin(); p2 != nums.end(); ) {
            if (*p1 == *p2) {
                --p2;
                nums.erase(p2);
            } else {
                ++p1;
                ++p2;
            }
        }
        return nums.size();
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{0, 0, 1, 2, 1, 2, 2, 3, 3, 4};
    Solution().removeDuplicates(v);
    return 0;
}
