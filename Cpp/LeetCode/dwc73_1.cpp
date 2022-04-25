#include "usual.h"

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        vector<int> cnt(1005);
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == key) {
                ++cnt[nums[i + 1]];
            }
        }
        int max_cnt = 0, ans = 0;
        for (int i = 0; i < 1005; ++i) {
            if (cnt[i] > max_cnt) {
                max_cnt = cnt[i];
                ans = i;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
