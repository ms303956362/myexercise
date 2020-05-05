#include "usual.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> s;
        int max_len = 1, num_max = nums[0], num_min = nums[0], tmp;
        int i = 0, j = 1;
        s.insert(nums[0]);
        for (; j != n; ++j) {
            if (j - i > max_len)
                max_len = j - i;
            s.insert(nums[j]);
            while (nums[j] > num_min + limit || nums[j] + limit < num_max) {
                tmp = nums[i];
                auto p = s.lower_bound(nums[i]);
                s.erase(p);
                if (tmp == num_min)
                    num_min = *(s.begin());
                if (tmp == num_max)
                    num_max = *(s.rbegin());
                ++i;
            }
            if (nums[j] > num_max)
                num_max = nums[j];
            if (nums[j] < num_min)
                num_min = nums[j];
        }
        if (j - i > max_len)
            max_len = j - i;
        return max_len;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{8,1,8,1,5,10,10};
    cout << Solution().longestSubarray(v, 7) << endl;
    return 0;
}
