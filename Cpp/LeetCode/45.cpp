#include "usual.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 1;
        for (int i = 0; i != nums.size(); ++i) {
            nums[i] += i;
        }
        for (int beg = 0, from = 0; nums[beg] < nums.size() - 1; ) {
            int max_beg = 0, max_pos = 0;
            for (int i = from + 1; i != nums.size() && i <= nums[beg]; ++i) {
                if (nums[i] > max_pos) {
                    max_pos = nums[i];
                    max_beg = i;
                }
            }
            from = nums[beg];
            beg = max_beg;
            ++cnt;
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{3, 2, 1};
    cout << Solution().jump(v) << endl;
    return 0;
}
