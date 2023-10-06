#include "usual.h"

class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        vector<int> target(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        auto right_move = [&n](vector<int>& a) {
            int tmp = a.back();
            for (int i = n - 1; i > 0; --i) {
                a[i] = a[i - 1];
            }
            a[0] = tmp;
        };
        for (int i = 0; i < n; ++i) {
            if (nums == target) {
                return i;
            }
            right_move(nums);
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{3,4,5,1,2};
    Solution().minimumRightShifts(a);
    return 0;
}
