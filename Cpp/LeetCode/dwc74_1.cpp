#include "usual.h"

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> cnt(505);
        for (const auto& num : nums) {
            ++cnt[num];
        }
        for (int i = 0; i <= 500; ++i) {
            if (cnt[i] % 2 == 1) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
