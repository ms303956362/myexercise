#include "usual.h"

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        while (true) {
            int min_num = INT_MAX;
            for (const auto& num : nums) {
                if (num != 0) {
                    min_num = min(min_num, num);
                }
            }
            if (min_num == INT_MAX) {
                break;
            }
            ++ans;
            for (auto& num : nums) {
                num -= min_num;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
