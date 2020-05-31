#include "usual.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_res = -1, res;
        for (int i = 0; i != nums.size() - 1; ++i) {
            for (int j = i + 1; j != nums.size();++j) {
                res = (nums[i] - 1) * (nums[j] - 1);
                if (res > max_res)
                    max_res = res;
            }
        }
        return max_res;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
