#include "usual.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return;
        int n = nums.size();
        k = k % n;
        int beg = 0;
        int cnt = 0;
        while (cnt < n) {
            int tmp = nums[beg];
            for (int i = beg - k; i != beg; i = i - k) {
                if (i < 0)
                    i = i + n;
                nums[(i + k) % n] = nums[i];
                ++cnt;
            }
            nums[(beg + k) % n] = tmp;
            ++beg;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    int k = 5;
    Solution().rotate(v, k);
    return 0;
}
