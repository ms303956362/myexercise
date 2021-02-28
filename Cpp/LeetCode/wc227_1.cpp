#include "usual.h"

class Solution {
public:
    bool check(vector<int>& nums) {
        int min_i = 0, n = nums.size();
        for (int i = 0; i != n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                min_i = i + 1;
                break;
            }
        }
        for (int i = min_i, cnt = 0; cnt != n - 1; i = (i + 1) % n, ++cnt) {
            if (nums[i] > nums[(i + 1) % n])
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
