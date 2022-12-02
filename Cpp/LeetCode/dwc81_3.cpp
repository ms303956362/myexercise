#include "usual.h"

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for (const auto& num : nums) {
            ans |= num;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
