#include "usual.h"

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0;
        for (const auto& num : nums) {
            if (num > 0) {
                ++cnt0;
            } else if (num < 0) {
                ++cnt1;
            }
        }
        return max(cnt0, cnt1);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
